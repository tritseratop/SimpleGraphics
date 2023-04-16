#pragma once

#define WIN32_LEAN_AND_MEAN
#define UNICODE
#include <windows.h>
#include <stdint.h>

#include "../api/Canvas.h"

namespace wingraph {

	class Bitmap;

	class Rectangle : public graph::Shape {
	public:
		Rectangle(std::shared_ptr<Bitmap> bitmap, const graph::Point& point, int a, int b, uint32_t color);

		void draw();

	private:
		std::shared_ptr<Bitmap> bitmap;
		graph::Point point;
		int height;
		int width;
		uint32_t color;
	};

	class Circle : public graph::Shape {
	public:
		Circle(std::shared_ptr<Bitmap> bitmap, const graph::Point& point, int r, uint32_t color);

		void draw();

	private:
		std::shared_ptr<Bitmap> bitmap;
		graph::Point point;
		int r;
		uint32_t color;
	};

	class WinShapeFactory : public graph::ShapeFactory {
	public:
		WinShapeFactory(std::shared_ptr<Bitmap> bitmap);

		std::unique_ptr<graph::Shape> createCircle(const graph::Point& point, int r, uint32_t color);
		std::unique_ptr<graph::Shape> createRectangle(const graph::Point& point, int a, int b, uint32_t color);
		std::unique_ptr<graph::Shape> createTiangle(const graph::Point& point, int h, int base, uint32_t color);

	private:
		std::shared_ptr<Bitmap> bitmap;
	};
}