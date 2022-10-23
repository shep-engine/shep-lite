#include "engine.h"

Engine::Engine(int w, int h, std::string title, Uint32 flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(w, h, flags, &window, &renderer);
    SDL_SetWindowTitle(window, title.c_str());
    running = true;
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

SDL_Surface* Graphics::load_img(const std::string &filePath)
{
    if (sprite_sheets.count(filePath) == 0)
    {
        sprite_sheets[filePath] = IMG_Load(filePath.c_str());
    }
    return sprite_sheets[filePath];
}

void Graphics::blit(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(renderer, tex, &src, &dst);
}