#pragma once
#include <SDL.h>

namespace Engine
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