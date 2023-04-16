#pragma once

#include <memory>

namespace graph {

	struct Point {
		int x = 0;
		int y = 0;
	};

	class Shape {
	public:
		Shape();
		virtual void draw() = 0;
		uint32_t getId() const;

		virtual ~Shape() = default;

	protected:
		static uint32_t count;
		uint32_t id;
	};

	enum class ShapeType {
		CIRCLE,
		RECTANGLE,
		TRIANGLE
	};

	class ShapeFactory {
	public:
		virtual std::unique_ptr<Shape> createCircle(const Point& point, int r, uint32_t color) = 0;
		virtual std::unique_ptr<Shape> createRectangle(const Point& point, int a, int b, uint32_t color) = 0;
		virtual std::unique_ptr<Shape> createTiangle(const Point& point, int h, int base, uint32_t color) = 0;

		virtual ~ShapeFactory() = default;
	};
}