#ifndef _PLAYER_H
#define _PLAYER_H

class Player
{
    private:
        float interval;
        float height;
        float speed;
        float max_speed;
        float accel;

    public:
        Player(float _interval, float _accel, float _height, float _max);
        bool has_crashed();
        float get_height();
        float get_speed();
        void set_speed(float val);
        void update();
};

#endif
