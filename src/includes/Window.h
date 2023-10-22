#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:
    Window(int width, int height);
    Window(const Window&) = delete;
    auto operator=(const Window&) = delete;
    ~Window();

    void show();
private:
    SDL_Window* window{ nullptr };
    SDL_Renderer* renderer{ nullptr };
    SDL_Event event{};
};
#endif
