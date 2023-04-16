#include "Canvas.h"

#include <vector>

namespace graph {
	Canvas::Canvas(CanvasParams params)
		: params(std::move(params))
	{}

	void Canvas::addShape(std::unique_ptr<Shape>&& shape) {
		shapes[shape->getId()] = std::move(shape);
	}
	void Canvas::deleteShape(uint32_t id) {
		shapes.erase(id);
	}
}