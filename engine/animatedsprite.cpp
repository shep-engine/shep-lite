#include "animatedsprite.h"
#include "engine.h"

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filePath, int srcx, int srcy, int w, int h, float x, float y, float frame_time)
    : Sprite(graphics, filePath, srcx, srcy, x, y, w, h), frame(0), frame_time(frame_time), visible(true), current_anim_once(false), current_anim("")
{
}

void AnimatedSprite::add_anim(int frames, int x, int y, std::string name, int w, int h, Vec2 offset)
{
    std::vector<SDL_Rect> rects;
    for (int i = 0; i < frames; i++)
    {
        SDL_Rect rect = { (i+x)*w, y, w, h };
        rects.push_back(rect);
    }
    anims.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rects));
    offsets.insert(std::pair<std::string, Vec2>(name, offset));
}

void AnimatedSprite::reset_anim()
{
    anims.clear();
    offsets.clear();
}

void AnimatedSprite::play_anim(std::string anim, bool once)
{
    current_anim_once = once;
    if (current_anim != anim)
    {
        current_anim = anim;
        frame = 0;
    }
}

void AnimatedSprite::stop_anim()
{
    frame = 0;
    anim_done(current_anim);
}

void AnimatedSprite::update(int dt)
{
    Sprite::update();
    timeElapsed += dt;
    if (timeElapsed > frame_time)
    {
        timeElapsed -= frame_time;
        if (frame < anims[current_anim].size() - 1)
        {
            frame++;
        } else 
        {
            if (current_anim_once == true)
            {
                set_visible(false);
            }
            frame = 0;
            anim_done(current_anim);
        }
    }
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y, int scale)
{
    if (visible)
    {
        SDL_Rect dst;
        dst.x = x + offsets[current_anim].x;
        dst.y = y + offsets[current_anim].y;
        dst.w = src_rect.w * scale;
        dst.h = src_rect.h * scale;

        SDL_Rect sourceRect = anims[current_anim][frame];
        graphics.blit(sprite_sheet, sourceRect, dst);
    }
}

void AnimatedSprite::anim_done(std::string current_anim)
{

}

void AnimatedSprite::init()
{
    add_anim(3, 0, 0, "run_left", 16, 16, Vec2(0,0));
    add_anim(3, 0, 16, "run_right", 16, 16, Vec2(0,0));
}