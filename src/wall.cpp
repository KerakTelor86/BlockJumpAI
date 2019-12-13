#include "wall.h"

Wall::Wall(float _interval, float _speed, float _width, float _position,
           float _hole_pos, float _hole_tolerance) :
    interval(_interval), speed(_speed), position(_position),
    width(_width), hole_pos(_hole_pos), hole_tolerance(_hole_tolerance)
{
}

float Wall::get_width()
{
    return width;
}

float Wall::get_position()
{
    return position;
}

float Wall::get_hole_position()
{
    return hole_pos;
}

float Wall::get_hole_height()
{
    return hole_tolerance * 2;
}

bool Wall::position_conflicts(Player &p)
{
    if(abs(position) > width / 2)
        return false;
    return abs(hole_pos - p.get_height()) > hole_tolerance;
}

void Wall::update()
{
    position += speed * interval;
}
