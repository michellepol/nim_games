#ifndef AI_H
#define AI_H

#include "headers/heap.h"
#include <QPair>

class AI
{
public:
    AI() = default;
    AI(Heap* heap1,Heap* heap2) {
        heap1_ = heap1;
        heap2_ = heap2;
    }
    void make_move_ai();
private:
    int NIM_sum();
    Heap* heap1_;
    Heap* heap2_;
};

#endif // AI_H
