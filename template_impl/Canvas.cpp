#include "Canvas.h"

namespace template_impl {

	TemplateCanvas::TemplateCanvas(graph::CanvasParams params)
		: Canvas(std::move(params))
	{}

	void TemplateCanvas::create()
	{
		// Create func
	}

	void TemplateCanvas::draw() {
		for (auto& [id, shape] : Canvas::shapes) {
			shape->draw();
		}
	}

	TemplateCanvas::~TemplateCanvas() {}
}