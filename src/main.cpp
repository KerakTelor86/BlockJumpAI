#include "game.h"

int main()
{
    srand(time(NULL));
    AI *ai = new AI(4, 1e-6);
    Game::reset();
    Game::train(ai);
    delete ai;
    return 0;
}
