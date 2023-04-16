#pragma once

#include <unordered_map>
#include <string>

#include "Shape.h"

namespace graph {

	struct CanvasParams {
		std::string name = "DefaultCanvas";
		int x = 2147483648U;
		int y = 2147483648U;
		int width = 2147483648U;
		int height = 2147483648U;
		uint32_t color = 0x333333;
	};

	class Canvas {
	public:
		Canvas(CanvasParams params);

		virtual void draw() = 0;
		virtual void create() = 0;

		void addShape(std::unique_ptr<Shape>&& shape);
		void deleteShape(uint32_t id);

	protected:
		CanvasParams params;
		std::unordered_map<uint32_t, std::unique_ptr<Shape>> shapes;
	};
}