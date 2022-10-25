#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include <string>
#include <vector>
#include "math.h"
#include "sprite.h"

class AnimatedSprite : public Sprite
{
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath, int srcx, int srcy, int w, int h, float x, float y, float frame_time);
    void play_anim(std::string anim, bool once = false);
    void update(int dt);
    void draw(Graphics &graphics, int x, int y, int scale=1);
    virtual void init();
protected:
    float frame_time;
    bool current_anim_once;
    std::string current_anim;

    void add_anim(int frames, int x, int y, std::string name, int w, int h, Vec2 offset);
    void reset_anim();
    void stop_anim();
    void set_visible(bool visible) {this->visible = visible;}
    virtual void anim_done(std::string current_anim);
private:
    std::map<std::string, std::vector<SDL_Rect>> anims;
    std::map<std::string, Vec2> offsets;
    int frame;
    double timeElapsed;
    bool visible;
}; 

#endif