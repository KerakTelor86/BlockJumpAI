#include "game.h"

int main()
{
    AI *ai = new AI(4, 1e-6);
    while(true)
    {
        srand(0);
        Game::reset();
        Game::train(ai);
    }
    delete ai;
    return 0;
}
