#pragma once

#define WIN32_LEAN_AND_MEAN
#define UNICODE
#include <windows.h>
#include <stdint.h>

#include "simple_graph_api/Canvas.h"

namespace wingraph {

	class Bitmap {
	public:
		Bitmap(HWND window);

		void paintPixel(int x, int y, uint32_t color);
		void cleanScreen(uint32_t color);
		void stretch();

		~Bitmap();

	private:
		void* bitmap_memory;

		int width;
		int height;
		const int bytes_per_pixel = 4;

		HDC device_context;
		BITMAPINFO bitmap_info;
	};

	class MainWindow : public graph::Canvas {
	public:
		static LRESULT CALLBACK WindowProc(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam);

		MainWindow(graph::CanvasParams params);

		void create() override;
		void draw() override;

		std::shared_ptr<Bitmap> getBitmap() const;

		~MainWindow();

	private:
		HWND window;

		std::shared_ptr<Bitmap> bitmap;
	};
}