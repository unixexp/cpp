#include <iostream>
#include <SDL2/SDL.h>

int main() {

    bool run = true;

    SDL_Event event;
    SDL_Window *window;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized: " << SDL_GetError() << std::endl;
    } else {
        std::cout << "SDL video system is ready to go\n";
        
        window = SDL_CreateWindow(
            "MainWindow",
            0,
            0,
            800,
            600,
            SDL_WINDOW_SHOWN
            );
        
        if (window == NULL) {
            std::cout << "SDL Window create error: " << SDL_GetError() << std::endl;
            return 1;
        }

        while (run) {
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    run = false;
                }
            }
        }

        SDL_DestroyWindow(window);

        SDL_Quit();
    }

    return 0;
}
