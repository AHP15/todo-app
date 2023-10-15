#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        // Handle initialization error
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << '\n';
        return 1;
    }

    SDL_Window *window{nullptr};
    window = SDL_CreateWindow(
        "Todo App",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        // Handle window creation error
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
        return 2;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
        return 3;
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    bool quit {false};
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

         // Clear the renderer
        SDL_RenderClear(renderer);

        // Draw a red rectangle
        SDL_Rect rect = {100, 100, 200, 150}; // X, Y, Width, Height
        SDL_RenderFillRect(renderer, &rect);

        // Present the renderer's content to the window
        SDL_RenderPresent(renderer);
    }

    // Cleanup and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
