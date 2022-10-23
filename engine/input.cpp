#include "input.h"

void Input::begin_new_frame()
{
    pressed_keys.clear();
    released_keys.clear();
}

void Input::key_down(const SDL_Event& event)
{
    pressed_keys[event.key.keysym.scancode] = true;
    held_keys[event.key.keysym.scancode] = true;
}

void Input::key_up(const SDL_Event& event)
{
    released_keys[event.key.keysym.scancode] = true;
    held_keys[event.key.keysym.scancode] = false;
}

bool Input::was_pressed(SDL_Scancode key)
{
    return pressed_keys[key];
}

bool Input::was_released(SDL_Scancode key)
{
    return released_keys[key];
}

bool Input::is_held(SDL_Scancode key)
{
    return held_keys[key];
}