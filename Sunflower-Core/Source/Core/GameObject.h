#pragma once
#include "vec2.h"
#include <vector>
#include "GraphicsManager.cpp"

namespace Sunflower
{
	class GameObject;

	struct Info
	{
		GameObject* self;
	};

	class GameObject
	{
	public:
		vec2 position;
		vec2 scale;

		virtual void on_start(Info info) {};
		virtual void on_update(Info info) {};
		virtual void on_render(Info info) {};
		virtual void on_input(Info info, Event ev) {};

	};
};