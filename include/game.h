#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <list>
#include <memory>
#include <random>
#include <vector>
#include <simple2d.h>
#include "player.h"
#include "wall.h"
#include "ai.h"

namespace Game
{
    static const float interval = 60.0/1000; // 60fps
    static const float game_speed = 100;
    static const int spawn_interval = 100;

    static const float gravity = 70;

    static const float wall_width = 100;
    static const float hole_height = 160;

    static const int screen_offset = 100;
    static const int game_width = 700;
    static const int game_height = 500;
    static const int window_x = 600;
    static const int window_y = 600;

    int convert_x(float x); // converts coordinates
    int convert_y(float y); // for display window
    void update();
    void render();

    static S2D_Window *window = NULL;
    static Player *player = NULL;
    static AI *ai = NULL;
    static int timer;
    static int score;
    static std::list<Wall> walls;

    void train(AI *_ai);
    void reset();
    int loop();
}

#endif
