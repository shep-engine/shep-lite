#include <iostream>
#include "sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Graphics &graphics, const std::string& filePath, int srcx, int srcy, float x, float y, int w, int h)
: x(x), y(y)
{
    src_rect.x =  srcx;
    src_rect.y = srcy;
    src_rect.w = w;
    src_rect.h = h;
    sprite_sheet = SDL_CreateTextureFromSurface(graphics.get_renderer(), graphics.load_img(filePath));
    if (sprite_sheet==nullptr)
    {
        std::cout << "Error: unable to load image from: "<< filePath << std::endl;
    }
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics, int x, int y, int scale)
{
    SDL_Rect dst = {x,y,src_rect.w*scale,src_rect.h*scale};
    graphics.blit(sprite_sheet, src_rect, dst);
}

void Sprite::update() {}