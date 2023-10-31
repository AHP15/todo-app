#include "Window.h"

int main()
{
    Window window { 680, 480 };

    bool running { true };
    while (running)
    {
        SDL_Event event { window.getEvent() };
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        window.show();
        Button button { "Click me", { 680/2, 480/2 } };
        window.RenderButton(button);
        if(!running) break;
    }
    
    
    return 0;
}
