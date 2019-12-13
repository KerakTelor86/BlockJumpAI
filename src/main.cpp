#include "game.h"

int main()
{
    srand(time(NULL));
    AI *ai = new AI(4, 0.01);
    for(int i = 0; i < 100; ++i)
    {
        Game::reset();
        Game::train(ai);
    }
    return 0;
}
