#include "winapi_graph/Canvas.h"
#include "winapi_graph/Shape.h"

#include <chrono>
#include <thread>

int WINAPI wWinMain(HINSTANCE Instance, HINSTANCE PrevInstance, PWSTR CmdLine, int CmdShow) {

	graph::CanvasParams params;
	wingraph::MainWindow main(std::move(params));
	main.create();

	wingraph::WinShapeFactory factory(main.getBitmap());
	auto rec = factory.createRectangle({ 100, 100 }, 64, 64, 0xff00ff);
	auto circle = factory.createCircle({ 200, 200 }, 16, 0xff00ff);
	auto circle2 = factory.createCircle({ 250, 250 }, 16, 0xff00ff);
	main.addShape(std::move(rec));
	main.addShape(std::move(circle));
	main.addShape(std::move(circle2));

	bool stop = false;
	while (!stop) {
		MSG message;
		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
			if (message.message == WM_QUIT) stop = true;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		main.draw();
	}

	return 0;
}
