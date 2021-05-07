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

void AI::make_random_move() {
    Heap* curr_heap;
    std::random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uid2(1,2);

    bool heaps_not_empty = false;
    if(heap2_->getCount() != 0 && heap1_->getCount() != 0) {
        uid2 = uniform_int_distribution<>(1, 3);
        heaps_not_empty = true;
    }
    int event = uid2(gen);

    if(event == 1 && heaps_not_empty) {
        curr_heap = heap1_;
    } else if(event == 2 && heaps_not_empty) {
        curr_heap = heap2_;
    } else if(event == 3) {
        heap1_->setCount(heap1_->getCount() - 1);
        heap2_->setCount(heap2_->getCount() - 1);
        return;
    } else {
        if( (event == 1 && heap1_->getCount() != 0) || heap2_->getCount() == 0) {
            curr_heap = heap1_;
        } else {
            curr_heap = heap2_;
        }
    }

    int stones;
    stones = curr_heap->getCount();

    curr_heap->setCount(stones - 1);
}

void AI::make_move_ai(bool flag) {
    int amount_of_stones;
    int nimsum = NIM_sum();

        std::random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> uid1(0, 5);
        bool mistake(false);
        /*
        if(uid1(gen) > 1) {
            mistake = false;
        }*/
        if(flag) {
            if(heap1_->getCount() == 1 && heap2_->getCount() == 1) {
                heap1_->setCount(0);
                heap2_->setCount(0);
                return;
            }
        }
        if (nimsum != 0 && mistake == false && flag) {
                if ((heap1_->getCount() ^ nimsum) < heap1_->getCount() && (heap1_->getCount() - (heap1_->getCount() ^ nimsum)) == 1) {
                    heap1_->setCount(heap1_->getCount() - 1);
                } else if((heap2_->getCount() ^ nimsum) < heap2_->getCount() && ( heap2_->getCount() - (heap2_->getCount() ^ nimsum)) == 1) {
                    heap2_->setCount(heap2_->getCount() - 1);
                } else {
                    make_random_move();
                }
        }
            else if(nimsum == 0 && !flag && mistake == false) {
            if(heap1_->getCount() == 1 && heap2_->getCount() == 1) {
                heap1_->setCount(0);
                return;
            }
            if ((heap2_->getCount() ^ nimsum) < heap2_->getCount() && (heap1_->getCount() - (heap1_->getCount() ^ nimsum)) == 1) {
                heap1_->setCount(heap1_->getCount() - 1);
            } else if((heap1_->getCount() ^ nimsum) < heap1_->getCount() && (heap2_->getCount() - (heap2_->getCount() ^ nimsum)) == 1) {
                heap2_->setCount(heap2_->getCount() - 1);
            } else {
                make_random_move();
            }
        } else {
            make_random_move();
        }

}

