#pragma once
#include "GameObject.h"

namespace Sunflower
{
	class Extender
	{
	public:
		virtual void on_start(Info info) {};
		virtual void on_update(Info info) {};
		virtual void on_render(Sunflower::Info info) {};
		virtual void on_input(Info info, Event ev) {};
		static void Create() {};
	};
};