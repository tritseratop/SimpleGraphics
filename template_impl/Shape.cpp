#pragma once

#define WIN32_LEAN_AND_MEAN
#define UNICODE

#include "Shape.h"

namespace template_impl {

	Rectangle::Rectangle(const graph::Point& point,
		int a, int b, uint32_t color)
		: point(point)
		, height(a)
		, width(b)
		, color(color)
	{}

	void Rectangle::draw() {
		// draw function
	}

	Circle::Circle(const graph::Point& point,
		int r, uint32_t color)
		: point(point)
		, r(r)
		, color(color)
	{}

	void Circle::draw() {
		// draw function
	}

	std::unique_ptr<graph::Shape> TemplateShapeFactory::createCircle(const graph::Point& point,
		int r, uint32_t color) {
		return std::make_unique<Circle>(point, r, color);
	}
	std::unique_ptr<graph::Shape> TemplateShapeFactory::createRectangle(const graph::Point& point,
		int a, int b, uint32_t color) {
		return std::make_unique<Rectangle>(point, a, b, color);
	}
	std::unique_ptr<graph::Shape> TemplateShapeFactory::createTiangle(const graph::Point& point,
		int h, int base, uint32_t color) {
		return nullptr;
	}
}