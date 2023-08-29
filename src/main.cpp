#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <BoxEngine.hpp>

static BoxEngine::Editor::ProjectManager* OpenProjectManager(bool external)
{
	using namespace BoxEngine::Editor;

	ProjectManager* manager = new ProjectManager();

	manager->Awake();
	manager->Start();

	if (!external)
		manager->Update();

	manager->Destroy();

	return manager;
}

int main(int argc, char* argv[])
{
	using namespace BoxEngine::Window;
	using namespace BoxEngine::GPU;
	using namespace BoxEngine::Debug;
	using namespace BoxEngine::Project;
	using namespace BoxEngine::Utils;
	using namespace BoxEngine::Editor;

	bool external = argc > 1;

	ProjectPtr project = nullptr;
	auto manager = OpenProjectManager(external);

	if (external)
	{
		auto projectName = argv[1];

		project = ProjectPtr(new Project());
		project->LoadFrom(projectName);
	}
	else
		project = manager->GetProject();

	delete manager;
	
	if (project == nullptr)
		return 0;
	
	Project::SetCurrentProject(project);

	EditorPtr editor = nullptr;

	if (!external)
	{
		editor = EditorPtr(new Editor());
		editor->SetCurrentEditor(editor);
		editor->Awake();
	}

	project->Load();

	Window::Init();
	Window::Maximize();
	Window::SetIcons({ ImagePtr(new Image(Directory::GetResourcePath() + "/icons/settings.png"))});

	if (!external)
		editor->Start();
	else
		project->Start();

	while(Window::ShouldRun())
	{	
		Framebuffer::ActiveDefault();
		Framebuffer::SetClearModes({ ClearMode::COLOR, ClearMode::DEPTH });
		Framebuffer::Clear({0.0f, 0.0f, 0.0f, 0.0f});
		
		if (!external)
		{
			editor->Update();
			project->SetScreenLimits(editor->GetTopStartPoint(), editor->GetBottomEndPoint());
		}
		else 
			project->SetScreenLimits({0, 0}, Window::GetSize());

		project->Execute();

		Window::SwapAndPollEvents();
	}

	if(!external)
		editor->Destroy();
	
	Window::Destroy();

	return 0;
}