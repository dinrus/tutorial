#include <CtrlLib/CtrlLib.h>

using namespace Upp;

struct MyAppWindow : TopWindow {
	MenuBar menu;

	void Exit() {
		if(PromptOKCancel("Exit MyApp?"))
			Break();
	}

	void SubMenu(Bar& bar) {
		bar.Add("Exit", [=, this] { Exit(); });
	}

	void MainMenu(Bar& bar) {
		bar.Sub("Menu", [=, this](Bar& bar) { SubMenu(bar); });
	}

	MyAppWindow() {
		Title("My application with menu").Sizeable();
		AddFrame(menu);
		menu.Set([=, this](Bar& bar) { MainMenu(bar); });
	}
};

GUI_APP_MAIN
{
	MyAppWindow app;
	app.Run();
}
