#include <BoxEngine.hpp>
#include "Editor.hpp"

namespace BoxEngine {
namespace Editor {

	using namespace Modules;

	std::weak_ptr<Editor> Editor::current;

	void Editor::Awake()
	{
		this->bottomBar.Awake();
		this->topBar.Awake();
		this->inspector.Awake();
		this->gameTree.Awake();

		this->camera = Camera::Camera2DPtr(new Camera::Camera2D());
	}

	void Editor::Start()
	{
		this->bottomBar.Start();
		this->topBar.Start();
		this->inspector.Start();
		this->gameTree.Start();

		Debug::Logging::Log(
			"[Editor]: Initialized",
			Debug::LogSeverity::Warning,
			Debug::LogOrigin::Engine
		);
	}

	void Editor::Update()
	{
		using namespace Window;

		GUI::BeginFrame();

		this->bottomBar.Update();

		this->inspector.SetMinY(this->bottomBar.GetMinY());
		this->inspector.Update();

		this->gameTree.SetMinY(this->bottomBar.GetMinY());
		this->gameTree.Update();
		this->topBar.Update();

		GUI::EndFrame();

		// Draw texture visualizer
		this->camera->SetLeft(0);
		this->camera->SetBottom(0);
		this->camera->SetTop(Modules::Window::Window::GetSize().y);
		this->camera->SetRight(Modules::Window::Window::GetSize().x);

		auto previous = Camera::Camera2D::GetCurrentCamera();
		Camera::Camera2D::SetCurrentCamera(this->camera);
		this->topBar.DrawTextureVisualizerTex();
		Camera::Camera2D::SetCurrentCamera(previous);
	}

	void Editor::Destroy()
	{
		this->bottomBar.Destroy();
		this->topBar.Destroy();
		this->inspector.Destroy();
		this->gameTree.Destroy();

		Debug::Logging::Log(
			"[Editor]: Released",
			Debug::LogSeverity::Warning,
			Debug::LogOrigin::Engine
		);
	}

	bool Editor::IsFocused()
	{
		glm::vec2 point = Modules::Input::Mouse::GetMousePosition(true);
		glm::vec2 topStartPoint = GetTopStartPoint(true);
		glm::vec2 bottomEndPoint = GetBottomEndPoint(true);

		bool isInsideX = (point.x >= topStartPoint.x) && (point.x <= bottomEndPoint.x);
		bool isInsideY = (point.y >= topStartPoint.y) && (point.y <= bottomEndPoint.y);

		if(Modules::Input::Mouse::GetMouseButtonState(Modules::Input::MouseButton::MOUSE_BUTTON_LEFT) >= Modules::Input::InputAction::PRESS)
			this->focused = !(isInsideX && isInsideY);

		return this->focused || this->topBar.IsFocused();
	}

	void Editor::InspectProjectSettings()
	{
		this->inspector.InspectProjectSettings();
	}

	void Editor::ClearLogs()
	{
		this->bottomBar.ClearLogs();
	}

	void Editor::InspectGo(std::string goId)
	{
		this->inspector.InspectGo(goId);
	}

	std::string Editor::GetInspectedGo()
	{
		return this->inspector.GetInspectedGo();
	}

	glm::vec2 Editor::GetTopStartPoint(bool correctY) const
	{
		// Min x, Min y
		return glm::vec2(this->gameTree.GetMaxX(), correctY ? Window::Window::GetSize().y - this->bottomBar.GetMinY() : this->bottomBar.GetMinY());
	}

	glm::vec2 Editor::GetBottomEndPoint(bool correctY) const
	{
		// Max x, Max y
		double maxY = correctY ? Window::Window::GetSize().y - TOPBAR_Y : Window::Window::GetSize().y;

		if (maxY < 0)
			maxY = 0;

		return glm::vec2(this->inspector.GetMinX(), maxY);
	}

	void Editor::SetShowPrivateVariables(bool value) 
	{
		this->showPrivateVariables = value;
	}

	bool Editor::GetShowPrivateVariables() const
	{
		return this->showPrivateVariables;
	}

	EditorPtr Editor::GetCurrentEditor()
	{
		if (current.expired())
			return nullptr;
		else
			return current.lock();
	}

	void Editor::SetCurrentEditor(EditorPtr editor)
	{
		current = editor;
	}
}}