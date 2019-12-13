#ifndef _AI_H
#define _AI_H

#include <list>
#include <vector>

class AI
{
    private:
        bool convert(float y);

        float alpha;
        std::size_t n;
        float bias;
        std::vector<float> theta;
        std::list<std::vector<float>> x_history;
        std::list<float> y_history;

    public:
        AI(std::size_t _n, float alpha);
        bool predict(std::vector<float> x);
        void fix(bool ans);
};

#endif
