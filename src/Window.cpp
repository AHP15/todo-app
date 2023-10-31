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
    SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Window::RenderButton(const Button& button)
{
    const Button::Point& point { button.getPoint() };
    const Style& style { button.getStyle() };
    SDL_Rect rect{ point.x, point.y, style.width, style.height };

    Style::Color color { button.getStyle().foreground };
    SDL_Color textColor = {
        color.red,
        color.blue,
        color.green
    }; // White color (RGBA format)
    const char* text { &button.getText() };
    SDL_Surface* textSurface {
        TTF_RenderText_Solid(font, text, textColor)
    };
    SDL_Texture* textTexture { SDL_CreateTextureFromSurface(renderer, textSurface) };


    SDL_RenderClear(renderer);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}