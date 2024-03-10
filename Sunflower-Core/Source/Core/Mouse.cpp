#pragma once
#include <SDL.h>

namespace Sunflower
{
	class Mouse_State
	{
    public:
		int x;
		int y;
		int button;
	};

	int x = 0;
	int y = 0;

	int mouse_button;
	void mouse_handle(SDL_Event e)
	{
		SDL_GetMouseState(&x, &y);
		mouse_button = e.button.button;
	};

    Mouse_State sunflower_get_mouse_state()
    {
        Mouse_State state;
        state.x = x;
        state.y = y;

        if (mouse_button == SDL_BUTTON_LEFT)
        {
            state.button = 1;
        }
        else if (mouse_button == SDL_BUTTON_MIDDLE)
        {
            state.button = 2;
        }
        else if (mouse_button == SDL_BUTTON_RIGHT)
        {
            state.button = 3;
        }
        else
        {
            state.button = 0;
        }

        return state;
    };
};