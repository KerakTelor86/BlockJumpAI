#include "ai.h"
#include <iostream>

AI::AI(std::size_t _n, float _alpha) :
    n(_n), theta(_n), bias(0), alpha(_alpha)
{
    theta[0] = 0.000462;
    theta[1] = 0.006851;
    theta[2] = -0.00620365;
    theta[3] = -0.0046305;
    bias = 6.5e-05;
}

bool AI::convert(float y)
{
    return y>=1;
}

bool AI::predict(std::vector<float> x)
{
    float y = bias;
    for(std::size_t i = 0; i < n; ++i)
    {
        y += x[i] * theta[i];
    }
    x_history.push_back(x);
    y_history.push_back(y);
    if(x_history.size() > 1000)
    {
        x_history.pop_front();
    }
    if(y_history.size() > 1000)
    {
        y_history.pop_front();
    }
    return convert(y);
}

void AI::fix(bool ans)
{
    // find first wrong prediction from the back
    std::vector<float> x;
    float y;
    do
    {
        x = x_history.back();
        y = y_history.back();
        x_history.pop_back();
        y_history.pop_back();
    } while(convert(y) == ans);

    float error = ans - convert(y);

    for(std::size_t i = 0; i < n; ++i)
    {
        theta[i] += error * alpha * x[i];
        std::cout << theta[i] << std::endl;
    }
    std::cout << bias << std::endl;
    
    bias += error * alpha;
}
