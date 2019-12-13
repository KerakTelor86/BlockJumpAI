#include "game.h"

int main()
{
    srand(time(NULL));
    AI *ai = new AI(4, 0.0001);
    for(int i = 0; i < 1000; ++i)
    {
        Game::reset();
        Game::train(ai);
    }
    return 0;
}
