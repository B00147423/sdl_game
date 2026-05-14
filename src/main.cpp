#include <iostream>
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    std::cout << "started\n";

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
        std::cin.get();
        return 1;
    }

    std::cout << "SDL initialized\n";

    SDL_Window* window = SDL_CreateWindow("SDL3 Window", 800, 600, 0);
    if (!window) {
        std::cerr << "Window failed: " << SDL_GetError() << "\n";
        std::cin.get();
        SDL_Quit();
        return 1;
    }

    std::cout << "window created\n";

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        std::cerr << "Renderer failed: " << SDL_GetError() << "\n";
        std::cin.get();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    std::cout << "renderer created\n";

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 20, 20, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}