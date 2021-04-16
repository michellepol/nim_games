#include "headers/ai.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#define computer 1
#define human 2

using namespace std;

//Функция, считающая нимсумму (xor)
int AI::NIM_sum() {
    int nimsum = heap1_->getCount() ^ heap2_->getCount();
    return nimsum;
}

void AI::make_move_ai() {
    int amount_of_stones;
    int nimsum = NIM_sum();

    try{
        std::random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> uid1(0, 1);
        bool mistake = uid1(gen);
        if (nimsum != 0 && mistake == false) {
                if ((heap1_->getCount() ^ nimsum) < heap1_->getCount()) {
                    amount_of_stones = heap1_->getCount() - (heap1_->getCount() ^ nimsum);
                    heap1_->setCount(heap1_->getCount() - amount_of_stones);
                } else {
                    amount_of_stones = heap2_->getCount() - (heap2_->getCount() ^ nimsum);
                    heap2_->setCount(heap2_->getCount() - amount_of_stones);
                }
        } else {
            int stones;
            Heap* curr_heap;
            if(uid1(gen) == 0 || heap2_->getCount() == 0) {
                stones = heap1_->getCount();
                curr_heap = heap1_;
            } else {
                stones = heap2_->getCount();
                curr_heap = heap2_;
            }
            uniform_int_distribution<> uid2(1, stones);

            amount_of_stones = uid2(gen);
            curr_heap->setCount(stones - amount_of_stones);
        }
    }
      catch (exception e) {
        qDebug(e.what());
    }


}

