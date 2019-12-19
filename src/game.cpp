#include "game.h"

int Game::convert_x(float x)
{
    return screen_offset + round(x / game_width * window_x);
}

int Game::convert_y(float y)
{
    return round((game_height - y) / game_height * window_y);
}

int Game::random_height()
{
    int range = game_height - hole_height;
    return hole_height / 2 + rand() % range;
}

void Game::reset()
{
    ai = NULL;
    delete player;
    if(window != NULL)
    {
        S2D_FreeWindow(window);
        window = NULL;
    }
    walls.clear();
    timer = 0;
    score = 0;
    player = new Player(interval, -gravity, (float) game_height / 2,
                        2 * gravity, - 1.85 * gravity, game_height);
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
}

void Game::train(AI *_ai)
{
    ai = _ai;
    S2D_Show(window);
}

void Game::update()
{
    if(walls.size() < 8 && timer == 0)
    {
        walls.emplace_back(interval, -game_speed, wall_width, game_width,
                           random_height(), hole_height / 2);
        timer = spawn_interval;
    }

    auto cur = walls.begin();
    if(cur->get_position() < -wall_width)
    {
        cur = std::next(walls.begin());
    }

    if(ai->predict({cur->get_position(), cur->get_hole_position(),
       player->get_height(), player->get_speed()}))
    {
        player->set_speed(1.5 * gravity);
    }

    if(player->has_crashed() || cur->position_conflicts(*player))
    {
        if(player->get_height() > cur->get_hole_position())
            ai->fix(false); // shouldn't have jumped, did
        else
            ai->fix(true);  // should've jumped, didn't

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

void Game::render()
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
