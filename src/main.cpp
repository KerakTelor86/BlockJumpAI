#include <iostream>
#include <list>
#include <memory>
#include <random>
#include "player.h"
#include "wall.h"

const float interval = 0.25;
const float game_speed = 1;
const float gravity = 3;
const int game_width = 5;
const int game_height = 10;
const int spawn_interval = 4;
const float wall_width = 1;
const float hole_height = 3;

int timer = 0;
int score = 0;

std::unique_ptr<Player> player(new
    Player(interval, -gravity, (float) game_height / 2, gravity)
);
std::list<Wall> walls;

bool loop(); // returns false when the game is lost

int main()
{
    srand(time(NULL));
    while(loop());
}

bool loop()
{
    if(walls.size() < game_width && timer == 0)
    {
        walls.emplace_back(interval, -game_speed, wall_width, game_width,
                           rand() % game_height, hole_height / 2);
        timer = 5;
    }

    auto cur = walls.begin();
    if(cur->get_position() < -wall_width)
    {
        cur = std::next(walls.begin());
    }

    if(player->has_crashed() || cur->position_conflicts(*player))
    {
        std::cout << "YOU LOSE!" << std::endl;
        return false;
    }

    std::cout << std::endl << std::endl;
    std::cout << "Score: " << score++ << std::endl;
    std::cout << std::endl;
    std::cout << "Height: " << player->get_height() << std::endl;
    std::cout << "Speed: " << player->get_speed() << std::endl;
    std::cout << std::endl;
    std::cout << "Distance to wall: ";
    std::cout << cur->get_position() - wall_width;
    std::cout << std::endl;
    std::cout << "Wall hole position: ";
    std::cout << cur->get_hole_position() << std::endl;
    std::cout << std::endl;
    std::cout << "Jump? ";

    int x;
    std::cin >> x;
    if(x)
        player->set_speed(gravity);

    player->update();
    for(auto &i : walls)
        i.update();
    if(walls.front().get_position() < wall_width)
    {
        walls.pop_front();
    }

    --timer;
    return true;
}
