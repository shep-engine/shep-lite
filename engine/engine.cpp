#include "engine.h"

Engine::Engine(int w, int h, std::string title, Uint32 flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(w, h, flags, &window, &renderer);
    SDL_SetWindowTitle(window, title.c_str());
    running = true;
}

void Engine::events()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                SDL_Quit();
                running = false;
                break;
            default:
                break;
        }
    }
}

void Engine::clear()
{
    SDL_RenderClear(renderer);
}

void Engine::render()
{
    SDL_RenderPresent(renderer);
}

Engine::~Engine()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}