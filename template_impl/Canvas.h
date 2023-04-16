#pragma once

#include "simple_graph_api/Canvas.h"

namespace template_impl {

	class TemplateCanvas : public graph::Canvas {
	public:

		TemplateCanvas(graph::CanvasParams params);

		void create() override;
		void draw() override;

		~TemplateCanvas();
	};
}