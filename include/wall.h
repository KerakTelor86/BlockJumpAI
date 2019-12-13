#ifndef _WALL_H
#define _WALL_H

#include <algorithm>
#include "player.h"

class Wall
{
    private:
        float interval;
        float speed;
        float width;
        float position;
        float hole_pos;
        float hole_tolerance;

    public:

        Wall(float _interval, float _speed, float _width,
             float _position, float _hole_pos,
             float _hole_tolerance);
        float get_width();
        float get_position();
        float get_hole_position();
        float get_hole_height();
        bool position_conflicts(Player &p);
        void update();
};

#endif
