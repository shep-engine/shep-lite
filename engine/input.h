#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL2/SDL.h>

class Input
{
public:
    void begin_new_frame();
    void key_up(const SDL_Event& event);
    void key_down(const SDL_Event& event);
    bool was_pressed(SDL_Scancode key);
    bool was_released(SDL_Scancode key);
    bool is_held(SDL_Scancode key);

private:
    std::map<SDL_Scancode, bool> held_keys;
    std::map<SDL_Scancode, bool> pressed_keys;
    std::map<SDL_Scancode, bool> released_keys;
};

#endif