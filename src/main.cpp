#include "game.h"

int main()
{
    // srand(time(NULL));
    AI *ai = new AI(4, 1e-6);
    for(int i = 0; i < 200; ++i)
    {
        Game::reset();
        Game::train(ai);
    }
    delete ai;
    return 0;
}
