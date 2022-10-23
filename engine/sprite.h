#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL.h>
#include "engine.h"

class Sprite
{
public:
    Sprite();
    Sprite(Graphics& graphics, const std::string &filePath, int srcx, int srcy, float x, float y, int w, int h);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y, int scale = 1);
private:
    SDL_Rect src_rect;
    SDL_Texture* sprite_sheet;

    float x, y;
};

#endif