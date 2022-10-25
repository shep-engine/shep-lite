#ifndef MATH_H
#define MATH_H

struct Vec2
{
    int x, y;
    Vec2() :x(0), y(0) {}
    Vec2(float x, float y) :x(x), y(y) {}
    Vec2 zero() {
        return Vec2(0,0);
    }
};


#endif //MATH_H
