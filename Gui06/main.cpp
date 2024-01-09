#include <CtrlLib/CtrlLib.h>

using namespace Upp;

struct MyAppWindow : TopWindow {
	void Close() override {
		delete this;
	}

	void LeftDown(Point pos, dword flags) override {
		(new MyAppWindow)->OpenMain();
	}

	void Paint(Draw& w) override {
		w.DrawRect(GetSize(), Brown());
		w.DrawText(0, 0, "Кликните в области видимости, чтобы открыть следующее окно!", Arial(20));
	}

	MyAppWindow() {
		Title("Многооконник").Zoomable().Sizeable();
	}
};

GUI_APP_MAIN
{
	(new MyAppWindow)->OpenMain();
	Ctrl::EventLoop();
}
