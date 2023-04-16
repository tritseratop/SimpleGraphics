#pragma once

#define WIN32_LEAN_AND_MEAN
#define UNICODE

#include "Shape.h"
#include "Canvas.h"

#include <windows.h>
#include <stdint.h>

#include "../api/Canvas.h"

namespace wingraph {

	Rectangle::Rectangle(std::shared_ptr<Bitmap> bitmap, const graph::Point& point,
		int a, int b, uint32_t color)
		: bitmap(bitmap)
		, point(point)
		, height(a)
		, width(b)
		, color(color)
	{}

	void Rectangle::draw() {
		for (int y = 0; y < width; ++y) {
			for (int x = 0; x < height; ++x) {
				bitmap->paintPixel(x + point.x, y + point.y, color);
			}
		}
	}

	Circle::Circle(std::shared_ptr<Bitmap> bitmap, const graph::Point& point,
		int r, uint32_t color)
		: bitmap(bitmap)
		, point(point)
		, r(r)
		, color(color)
	{}

	void Circle::draw() {
		for (int y = 0; y < r * 2; ++y) {
			for (int x = 0; x < r * 2; ++x) {
				if ((x - r) * (x - r) + (y - r) * (y - r) < r * r) {
					bitmap->paintPixel(x + point.x, y + point.y, color);
				}
			}
		}
	}

	WinShapeFactory::WinShapeFactory(std::shared_ptr<Bitmap> bitmap)
		: bitmap(bitmap)
	{}

	std::unique_ptr<graph::Shape> WinShapeFactory::createCircle(const graph::Point& point,
		int r, uint32_t color) {
		return std::make_unique<Circle>(bitmap, point, r, color);
	}
	std::unique_ptr<graph::Shape> WinShapeFactory::createRectangle(const graph::Point& point,
		int a, int b, uint32_t color) {
		return std::make_unique<Rectangle>(bitmap, point, a, b, color);
	}
	std::unique_ptr<graph::Shape> WinShapeFactory::createTiangle(const graph::Point& point,
		int h, int base, uint32_t color) {
		return nullptr;
	}
}