#include "Shape.h"

namespace graph {

	Shape::Shape() {
		id = count++;
	}

	uint32_t Shape::getId() const {
		return id;
	}

	uint32_t Shape::count = 0;
}