#include "game.h"

int main()
{
    srand(time(NULL));
    AI *ai = new AI(4, 0.0001);
    Game::reset();
    Game::train(ai);
    delete ai;
    return 0;
}
