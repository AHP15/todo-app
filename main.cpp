#include <SDL2/SDL.h>
#include <iostream>

#include "TodoConfig.h"

int main()
{
    std::cout << "Todo version " << TODO_VERSION_MAJOR << TODO_VERSION_MINOR << '\n';
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window* window{};
    SDL_Renderer* renderer{};
    SDL_Event event{};

    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    SDL_Rect rec{10, 10, 250, 250};

    bool running {true};
    bool skip {false};
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    rec.x += 10;
                    break;
                default:
                    break;
                }

            } else if (event.type == SDL_KEYUP) {

            } else if (event.type == SDL_MOUSEMOTION) {
                // SDL_GetMouseState(&rec.x, &rec.y);
            } else if(event.type == SDL_MOUSEBUTTONDOWN) {
                if(skip) {
                    skip = false;
                } else {
                    skip = true;
                }
                SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 225, 250, 0, 255);
                SDL_RenderFillRect(renderer, &rec);
                SDL_RenderPresent(renderer);
            }
        }

        if(skip) continue;
        
        SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 245, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rec);

        SDL_RenderPresent(renderer);
    }
    

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
