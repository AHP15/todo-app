#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL/SDL_ttf.h>

#include "Button.h"

class Window
{
public:
    Window(int width, int height);
    Window(const Window&) = delete;
    auto operator=(const Window&) = delete;
    ~Window();

    void show();
    void RenderButton(const Button& button);

    const SDL_Event& getEvent() { return event; }
private:
    SDL_Window* window{ nullptr };
    SDL_Renderer* renderer{ nullptr };
    SDL_Event event{};
    TTF_Font* font { TTF_OpenFont("path/to/your/font.ttf", 16) };
};
#endif
