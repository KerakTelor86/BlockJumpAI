#include <iostream>
#include <list>
#include <memory>
#include <random>
#include <simple2d.h>
#include "player.h"
#include "wall.h"

const float interval = 60.0/1000; // 60fps
const float game_speed = 100;
const int spawn_interval = 100;

const float gravity = 70;

const float wall_width = 100;
const float hole_height = 160;

const int screen_offset = 100;
const int game_width = 700;
const int game_height = 500;
const int window_x = 600;
const int window_y = 600;

S2D_Window *window;

int convert_x(float x); // converts coordinates
int convert_y(float y); // for display window
void update();
void render();
void on_key(S2D_Event e);

int main()
{
    srand(time(NULL));
    window = S2D_CreateWindow
    (
        "BlockJump",
        window_x, window_y,
        update, render,
        0
    );
    window->background.r = 1;
    window->background.g = 1;
    window->background.b = 1;
    window->on_key = on_key;
    S2D_Show(window);
    S2D_FreeWindow(window);
    return 0;
}

int convert_x(float x)
{
    return screen_offset + round(x / game_width * window_x);
}

int convert_y(float y)
{
    return round((game_height - y) / game_height * window_y);
}

int timer = 0;
int score = 0;

std::unique_ptr<Player> player(new
    Player(interval, -gravity, (float) game_height / 2, 2 * gravity,
           - 1.85 * gravity, game_height)
);

std::list<Wall> walls;

void update()
{
    if(walls.size() < 8 && timer == 0)
    {
        walls.emplace_back(interval, -game_speed, wall_width, game_width,
                           rand() % game_height, hole_height / 2);
        timer = spawn_interval;
    }

    auto cur = walls.begin();
    if(cur->get_position() < -wall_width)
    {
        cur = std::next(walls.begin());
    }

    if(player->has_crashed() || cur->position_conflicts(*player))
    {
        std::cout << "FINAL SCORE: " << score << std::endl;
        S2D_Close(window);
    }
    else
    {
        player->update();
        for(auto &i : walls)
        {
            i.update();
        }
        if(walls.front().get_position() < - 2 * wall_width)
        {
            std::cout << ++score << std::endl;
            walls.pop_front();
        }

        --timer;
    }
}

void render()
{
    // draw player
    int player_x = convert_x(0);
    int player_y = convert_y(player->get_height());
    S2D_DrawQuad
    (
        player_x - 20, player_y + 20, 1, 0, 0, 1,
        player_x + 20, player_y + 20, 1, 0, 0, 1,
        player_x + 20, player_y - 20, 1, 0, 0, 1,
        player_x - 20, player_y - 20, 1, 0, 0, 1
    );

    // draw walls
    for(auto &i : walls)
    {
        int wall_x0 = convert_x(i.get_position() - i.get_width() / 2);
        int wall_x1 = convert_x(i.get_position() + i.get_width() / 2);
        int wall_yh0 = convert_y(i.get_hole_position() + hole_height / 2);
        int wall_yh1 = convert_y(i.get_hole_position() - hole_height / 2);
        int wall_y0 = 0;
        int wall_y1 = window_y;
        S2D_DrawQuad
        (
            wall_x0, wall_y0,  0, 0, 0.7, 1,
            wall_x0, wall_yh0, 0, 0, 0.7, 1,
            wall_x1, wall_yh0, 0, 0, 0.7, 1,
            wall_x1, wall_y0,  0, 0, 0.7, 1
        );
        S2D_DrawQuad
        (
            wall_x0, wall_yh1, 0, 0, 0.7, 1,
            wall_x0, wall_y1,  0, 0, 0.7, 1,
            wall_x1, wall_y1,  0, 0, 0.7, 1,
            wall_x1, wall_yh1, 0, 0, 0.7, 1
        );
    }
}

void on_key(S2D_Event e)
{
    switch(e.type)
    {
        case S2D_KEY_DOWN:
            player->set_speed(1.5 * gravity);
    }
}
