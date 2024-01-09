#include <CtrlLib/CtrlLib.h>

using namespace Upp;

struct MyAppWindow : TopWindow {
	MenuBar menu;

	MyAppWindow() {
		Title("Приложение с Менюшкой").Sizeable();
		AddFrame(menu);
		menu.Set(
			[=, this](Bar& bar) {
				bar.Sub("Менюшка",
						[=, this](Bar& bar) {
							bar.Add("Выход",
								[=, this] {
									if(PromptOKCancel("Покинуть MyApp?"))
										Break();
								}
							);
						}
				);
			}
		);
	}
};

GUI_APP_MAIN
{
	MyAppWindow app;
	app.Run();
}
