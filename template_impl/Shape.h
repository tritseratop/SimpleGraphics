#pragma once

#include "simple_graph_api/Shape.h"

namespace template_impl {

	class TemplateShapeFactory : public graph::ShapeFactory {
	public:
		std::unique_ptr<graph::Shape> createCircle(const graph::Point& point, int r, uint32_t color);
		std::unique_ptr<graph::Shape> createRectangle(const graph::Point& point, int a, int b, uint32_t color);
		std::unique_ptr<graph::Shape> createTiangle(const graph::Point& point, int h, int base, uint32_t color);
	};

	class Rectangle : public graph::Shape {
	public:
		Rectangle(const graph::Point& point, int a, int b, uint32_t color);

		void draw();

	private:
		graph::Point point;
		int height;
		int width;
		uint32_t color;
	};

	class Circle : public graph::Shape {
	public:
		Circle(const graph::Point& point, int r, uint32_t color);

		void draw();

	private:
		graph::Point point;
		int r;
		uint32_t color;
	};
}