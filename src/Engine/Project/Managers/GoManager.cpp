#include <BoxEngine.hpp>
#include "GoManager.hpp"

namespace BoxEngine {
namespace Project {

    void GoManager::Load(nlohmann::json& data)
    {
        using namespace BoxEngine::Utils;
        using namespace std::placeholders;

        Debug::Logging::Log("[Project]: Loading gos", Debug::LogSeverity::Warning, Debug::LogOrigin::Engine);
        Serialization::DeserializeGo(data["scene"], "", std::bind(&GoManager::AddGameObjectFromFile, this, _1, _2, _3, _4, _5));
    }

    void GoManager::Unload()
    {
        // Remove all references
        this->gosMap.clear();
        
        // Remove recursive
        this->RecursiveRemoveGos(this->gos);
        
        // Remove root
        this->gos.clear();
    }

    std::vector<GameObjectPtr>& GoManager::GetRootGameObjects()
    {
        return this->gos;
    }

    GameObjectPtr GoManager::GetGameObject(const std::string& id)
    {
        if (this->gosMap.contains(id))
            return this->gosMap[id];

        return nullptr;
    }

    GameObjectPtr GoManager::AddGameObject(const std::string& name, bool active, const std::string& fatherId)
    {
        GameObjectPtr newGo = GameObjectPtr(new GameObject());
        GameObjectPtr fatherGo = nullptr;

        newGo->id = this->NewGoId();
        newGo->name = name.size() == 0 ? "New Game Object" : name;
        newGo->active = active;
        newGo->toDestroy = false;

        if (fatherId.size() > 0)
        {
            if (this->gosMap.contains(fatherId))
            {
                fatherGo = this->gosMap.at(fatherId);

                if (fatherGo->IsToDestroy())
                {
                    Debug::Logging::Log(
                        "[Project]: When creating go " + name + ": father with id " + fatherId + " is set to be destroyed", 
                        Debug::LogSeverity::Error, 
                        Debug::LogOrigin::Engine,
                        {{"father_id", fatherId}}
                    );

                    return nullptr;
                }
            }
            else
            {
                Debug::Logging::Log("[Project]: When creating go " + name + ": Can't find father with id " + fatherId, Debug::LogSeverity::Error, Debug::LogOrigin::Engine);
                return nullptr;
            }
        }

        newGo->SetFather(fatherGo);

        if (fatherGo != nullptr)
            fatherGo->childrens.push_back(newGo);
        else
            this->gos.push_back(newGo);

        this->gosMap[newGo->id] = newGo;

        return newGo;
    }

    bool GoManager::RemoveGameObject(const std::string& id)
    {
        if (this->gosMap.contains(id))
            RemoveGameObject(this->gosMap[id]);
        else
        {
            Debug::Logging::Log("[Project]: Can't find go with " + id + " to be destroyed.", Debug::LogSeverity::Warning, Debug::LogOrigin::Engine);
            return false;
        }

        return true;
    }

    void GoManager::RemoveGameObject(GameObjectPtr go)
    {
        go->SetToDestroy();
    }

    void GoManager::RemoveGameObjectReferences(GameObjectPtr go)
    {
        RemoveGameObjectReferences(go->GetId());
    }

    void GoManager::RemoveGameObjectReferences(const std::string& id)
    {
        // Era ref from father or root, and then the childrens
        if (this->gosMap.contains(id))
        {
            auto go = this->gosMap[id];
            auto father = go->GetFather();

            if (father == nullptr)
            {
                std::erase_if(this->gos, [&go](const auto& item) {
                    return item->GetId() == go->GetId();
                });
            }
            else
            {
                std::erase_if(go->GetFather()->GetChildrens(), [&go](const auto& item) {
                    return item->GetId() == go->GetId();
                });
            }

            this->gosMap.erase(id);
            
            // Then just erase the remaining.
            RecursiveRemoveGos(go->childrens);
            go->childrens.clear();
        }
    }

    #pragma region InternalFunctions

    void GoManager::AddGameObjectFromFile(
        const std::string& id, 
        const std::string& name, 
        bool active, 
        const std::vector<ScriptPtr>& scripts,
        const std::string fatherId
    )
    {
        GameObjectPtr newGo = GameObjectPtr(new GameObject());
        GameObjectPtr fatherGo = nullptr;

        newGo->name = name.size() == 0 ? "New Game Object" : name;
        newGo->id = id;
        newGo->active = active;
        newGo->scripts = scripts;

        auto scriptsList = Project::GetCurrentProject()->GetScriptNamesForEditor();
        for (const auto& script : scripts)
        {
            if (std::find_if(
                scriptsList.begin(), 
                scriptsList.end(), 
                [&script](const auto& x) { return x == script->GetName(); }) == scriptsList.end()
             )
            {
                script->MarkAsFailedToLoad();
                Debug::Logging::Log("[Project]: When loading go " + name + " with id " + id + " script " + script->GetName() + " not founded!", Debug::LogSeverity::Warning, Debug::LogOrigin::Engine);
            }
        }

        if (this->gosMap.contains("id"))
        {
            Debug::Logging::Log("[Project]: Go " + name + " with id " + id + " already exists. It will be ignored with it childrens.", Debug::LogSeverity::Error, Debug::LogOrigin::Engine);
            return;
        }

        if (fatherId.size() > 0)
        {
            if (this->gosMap.contains(fatherId))
                fatherGo = this->gosMap.at(fatherId);
            else
            {
                Debug::Logging::Log("[Project]: Failed to create go " + name + ": Can't find father with id " + fatherId, Debug::LogSeverity::Error, Debug::LogOrigin::Engine);
                return;
            }
        }

        newGo->SetFather(fatherGo);

        if (fatherGo != nullptr)
            fatherGo->childrens.push_back(newGo);
        else
            this->gos.push_back(newGo);

        this->gosMap[newGo->id] = newGo;
    }

    void GoManager::RecursiveRemoveGos(std::vector<GameObjectPtr>& gos)
    {
        for (const GameObjectPtr& go : gos)
        {
            this->gosMap.erase(go->GetId());
            RecursiveRemoveGos(go->GetChildrens());
            gos.clear();
        }
    }

    std::string GoManager::NewGoId()
    {
        std::string id = Utils::Directory::NewGuid().substr(0, 10);

        while (true)
        {
            if (!this->gosMap.contains(id))
                break;

            id = Utils::Directory::NewGuid().substr(0, 10);
        }

        return id;
    }
    
    #pragma endregion
}}