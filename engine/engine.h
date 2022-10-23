#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Engine
{
public:
    Engine(int w, int h, std::string title, Uint32 flags);
    void events();
    void clear();
    void render();
    
    bool isRunning() {return running;}
    void setRunning(bool new_running) {running = new_running;}
    virtual ~Engine();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
};

#endif