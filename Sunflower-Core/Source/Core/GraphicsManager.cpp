#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Image.h"
#include <iostream>
#include "vec2.h"
#include <SDL_ttf.h>
#include <functional>
#include "Mouse.cpp"

struct Event
{
    SDL_Event* ev;
    unsigned int scancode;
};

namespace Sunflower
{
    SDL_Event event;
    bool quit;
    SDL_Renderer* renderer;
    SDL_Window* window;
    int w;
    int h;
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

    

    SDL_Event HandleEvents(std::function<void(Event ev)> func)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            func(Event(&event, event.key.keysym.scancode));
            mouse_handle(event);
        }
        return event;
        SDL_GetWindowSize(window, &w, &h);
    }
    
    void EndRender()
    {
        SDL_RenderPresent(renderer);
    }

    void DrawBackground(float r, float g, float b)
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);

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
        float w = scale.x*image.w;
        float h = scale.y*image.h;
        SDL_Rect destRect = { position.wstss(w,h).x, position.wstss(w,h).y, w, h};

        SDL_RenderCopy(renderer, image.texture, NULL, &destRect);
    }


    void MainLoopEnd()
    {
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    void Flush()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_Renderer* GetRenderer()
    {
        return renderer;
    }
    SDL_Window* GetWindow()
    {
        return window;
    }
};