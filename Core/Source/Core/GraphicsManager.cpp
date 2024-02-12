#include <SDL.h>
#include <SDL_image.h>
#include "Image.h"
#include <iostream>
#include "vec2.h"

namespace Engine
{
    SDL_Event event;
    bool quit;
    SDL_Renderer* renderer;
    SDL_Window* window;
    bool InitRenderer(const char* title, int width, int height)
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
            return false;
        }
        // Create a window
        window = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return false;
        }

        // Create a renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            SDL_DestroyWindow(window);
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return false;
        }
        int imgFlags = IMG_INIT_PNG; // You can use other image formats too
        if (!(IMG_Init(imgFlags) & imgFlags)) {
            std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
            SDL_Quit();
            return false;
        }

        return true;
    }

    void PreMainLoop()
    {
        quit = false;
    }

    void HandleEvents()
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
    
    void EndRender()
    {
        SDL_RenderPresent(renderer);
    }

    void DrawBackground(float r, float g, float b)
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);

        // Clear the renderer
        SDL_RenderClear(renderer);
    }

    Image LoadImage(const char* path)
    {
        SDL_Surface* imageSurface = IMG_Load(path);
        if (imageSurface == nullptr) {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
            SDL_Quit();
        }

        // Create texture from surface
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        if (texture == nullptr) {
            SDL_FreeSurface(imageSurface);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
        }
        return Image(texture, imageSurface, imageSurface->w, imageSurface->h);
    }

    void DrawImage(Image image, vec2 scale, vec2 position)
    {
        float w = scale.a*image.w;
        float h = scale.b*image.h;
        SDL_Rect destRect = { 100, 100, w, h};

        SDL_RenderCopy(renderer, image.texture, NULL, &destRect);
    }

    void MainLoopEnd()
    {
        SDL_Delay(10);
    }

    void Flush()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};