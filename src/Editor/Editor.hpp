#pragma once
#include <BoxEngine.hpp>

namespace BoxEngine {
namespace Editor {

	class Editor;
	typedef std::shared_ptr<Editor> EditorPtr;

	class Editor : public Layout
	{
	private:
		TopBar topBar;
		Inspector inspector;
		GameTree gameTree;
		BottomWindow bottomBar;

		static std::weak_ptr<Editor> current;
	public:
		Editor() = default;
		~Editor() = default;

		void Awake();
		void Start();
		void Update();
		void Destroy();

		void InspectProjectSettings();
		void ClearLogs();
		void InspectGo(Project::GameObjectWeakPtr go);
		
		glm::vec2 GetTopStartPoint() const;
		glm::vec2 GetBottomEndPoint() const;

		static EditorPtr GetCurrentEditor();
		static void SetCurrentEditor(EditorPtr editor);
	};
}}