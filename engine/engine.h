#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <map>

class Engine
{
public:
    Engine(int w, int h, std::string title, Uint32 flags);
    void events();
    void render();
    void clear();
    void set_running(bool new_running) {running = new_running;}

    bool is_running() {return running;}
    SDL_Window* get_window() {return window;}
    SDL_Renderer* get_renderer() {return renderer;}

    virtual ~Engine();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
};

class Graphics
{
public:
    Graphics(SDL_Renderer* renderer) {this->renderer = renderer;}
    SDL_Surface* load_img(const std::string& filePath);
    void blit(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);
    void flip();
    SDL_Renderer* get_renderer() {return renderer;}
private:
    std::map<std::string, SDL_Surface*> sprite_sheets;
    SDL_Renderer* renderer;
};

#endif