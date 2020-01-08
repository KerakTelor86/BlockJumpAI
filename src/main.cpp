#include "game.h"

int main()
{
    AI *ai = new AI(4, 1e-6);
    int iter = 0;
    while(true)
    {
        std::cout << "\n\nIteration #" << ++iter << std::endl;
        srand(0);
        Game::reset();
        Game::train(ai);
    }
    delete ai;
    return 0;
}
