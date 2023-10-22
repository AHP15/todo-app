#include "Window.h"

#include <SDL2/SDL.h>

Window::Window(int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
}


Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::show()
{
    bool running {true};
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        if(!running) break;
    }
    
}