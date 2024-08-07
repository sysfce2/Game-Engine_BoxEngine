#include <BoxEngine.hpp>
#include "BottomWindow.hpp"

namespace BoxEngine {
namespace Editor {
	
	using namespace Modules;

	void BottomWindow::Awake()
	{
		this->logTab.Awake();
		this->filesTab.Awake();
		this->infoTab.Awake();
	}

	void BottomWindow::Start()
	{
		this->logTab.Start();
		this->filesTab.Start();
		this->infoTab.Start();
	}

	void BottomWindow::Update()
	{
		using namespace Window;
		using Window = Modules::Window::Window;

		auto size = Window::GetSize();

		if (this->reset)
		{
			GUI::SetNextWindowPosition({ 0, size.y * 0.7 });
			GUI::SetNextWindowSize({ size.x, (size.y * 0.3) });

			this->reset = false;
		}

		if (GUI::BeginWindow("Navigator", nullptr, { GUIWindowFlags::NoMove, GUIWindowFlags::NoCollapse, GUIWindowFlags::NoBringToFrontOnFocus }))
		{
			auto guiPosition = GUI::GetWindowPosition();
			auto guiSize = GUI::GetWindowSize();

			if (guiSize.x != size.x || std::abs(guiPosition.y + guiSize.y - Window::GetSize().y) > 2)
				this->reset = true;

			this->minY = GUI::GetWindowPosition().y;

			if (GUI::BeginTabBar("NavigatorTabs"))
			{
				if (GUI::BeginTabItem("Logs"))
				{
					this->logTab.Update();
					GUI::EndTabItem();
				}

				if (GUI::BeginTabItem("Files"))
				{
					GUI::SetFontScale(0.7);
					this->filesTab.Update();
					GUI::SetFontScale(1);

					GUI::EndTabItem();
				}

				if (GUI::BeginTabItem("Info"))
				{
					this->infoTab.Update();
					GUI::EndTabItem();
				}

				GUI::EndTabBar();
			}

			this->focused = GUI::IsCurrentWindowFocused() || GUI::IsAnyItemFocused();
			GUI::EndWindow();
		}
		else this->focused = false;
	}

	void BottomWindow::Destroy()
	{
		this->logTab.Destroy();
		this->filesTab.Destroy();
		this->infoTab.Destroy();
	}

	void BottomWindow::Reset()
	{
		this->logTab.Reset();
		this->filesTab.Reset();
		this->infoTab.Reset();

		this->reset = true;
	}

	void BottomWindow::ClearLogs()
	{
		this->logTab.ClearLogs();
	}

	bool BottomWindow::Focused()
	{
		return this->focused;
	}

	float BottomWindow::GetMinY() const
	{
		if (this->minY < 0)
			return 0;

		return this->minY;
	}
}}

