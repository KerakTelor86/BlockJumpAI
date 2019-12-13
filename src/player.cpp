#include "player.h"

Player::Player(float _interval, float _accel, float _height, float _max) :
    interval(_interval), accel(_accel), height(_height),
    max_speed(_max), speed(0)
{
}

bool Player::has_crashed()
{
    return height <= 0;
}

float Player::get_height()
{
    return height;
}

float Player::get_speed()
{
    return speed;
}

void Player::set_speed(float val)
{
    speed = val;
}

void Player::update()
{
    // High school physics equation
    // pos1 = pos0 + (v*t) + (a*t^2)/2
    height = height + speed * interval + accel * interval * interval / 2;
    speed = speed + accel * interval;
    if(speed < -max_speed)
        speed = -max_speed;
    else if(speed > max_speed)
        speed = max_speed;
}
