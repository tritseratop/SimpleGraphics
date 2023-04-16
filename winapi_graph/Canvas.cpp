#include "Canvas.h"

namespace wingraph {

	Bitmap::Bitmap(HWND window) {
		RECT client_rect;
		GetClientRect(window, &client_rect);
		width = client_rect.right - client_rect.left;
		height = client_rect.bottom - client_rect.top;

		bitmap_memory = VirtualAlloc(0,
			width * height * bytes_per_pixel,
			MEM_RESERVE | MEM_COMMIT,
			PAGE_READWRITE
		);

		bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
		bitmap_info.bmiHeader.biWidth = width;
		bitmap_info.bmiHeader.biHeight = -height;
		bitmap_info.bmiHeader.biPlanes = 1;
		bitmap_info.bmiHeader.biBitCount = 32;
		bitmap_info.bmiHeader.biCompression = BI_RGB;

		device_context = GetDC(window);
	}

	void Bitmap::paintPixel(int x, int y, uint32_t color) {
		uint32_t* pixel = static_cast<uint32_t*>(bitmap_memory);
		pixel += y * width + x;
		*pixel = color;
	}

	void Bitmap::cleanScreen(uint32_t color) {
		uint32_t* pixel = static_cast<uint32_t*>(bitmap_memory);
		for (int i = 0; i < width * height; ++i) {
			*pixel++ = color;
		}
	}

	void Bitmap::stretch() {
		StretchDIBits(device_context, 0, 0,
			width, height,
			0, 0,
			width, height,
			bitmap_memory, &bitmap_info,
			DIB_RGB_COLORS, SRCCOPY);
	}

	Bitmap::~Bitmap() {
		VirtualFree(0, width * height * bytes_per_pixel, MEM_FREE);
	}

	LRESULT CALLBACK MainWindow::WindowProc(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam) {
		switch (Message) {
		case WM_KEYDOWN: {
			switch (WParam) {
			case 'O': { DestroyWindow(Window); };
			}
		} break;
		case WM_DESTROY: {
			PostQuitMessage(0);
		} break;
		default: {
			return DefWindowProc(Window, Message, WParam, LParam);
		}
		}
		return 0;
	}

	MainWindow::MainWindow(graph::CanvasParams params)
		: Canvas(std::move(params))
		, window(nullptr)
	{}

	void MainWindow::create()
	{
		WNDCLASS window_class = { 0 };

		window_class.lpfnWndProc = MainWindow::WindowProc;
		window_class.hInstance = GetModuleHandle(NULL);

		const wchar_t class_name[] = L"MyWindowClass";
		window_class.lpszClassName = class_name;
		window_class.hCursor = LoadCursor(0, IDC_CROSS);

		RegisterClass(&window_class);

		window = CreateWindowEx(0, class_name, L"Program",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE, params.x, params.y,
			params.width, params.height, 0, 0, GetModuleHandle(NULL), 0);

		bitmap = std::make_shared<Bitmap>(window);
	}

	std::shared_ptr<Bitmap> MainWindow::getBitmap() const {
		return bitmap;
	}

	void MainWindow::draw() {
		bitmap->cleanScreen(Canvas::params.color);
		for (auto& [id, shape] : Canvas::shapes) {
			shape->draw();
		}
		bitmap->stretch();
	}

	MainWindow::~MainWindow() {
		DestroyWindow(window);
	}
}