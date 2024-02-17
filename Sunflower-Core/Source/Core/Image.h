#pragma once
#include <SDL.h>

namespace Sunflower
{
	struct Image
	{
	public:
		SDL_Texture* texture;
		SDL_Surface* surface;
		float w;
		float h;
	};
};