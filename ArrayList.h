//
// Created by Blue Sky on 4/4/20.
//

#ifndef SURAKARTA_ZERO_ARRAYLIST_H
#define SURAKARTA_ZERO_ARRAYLIST_H

#include "basic.h"
class ArrayList{
public:
    ArrayList();
    void clear();
    int size();
    bool unempty();
    void push(singleMove x);
    singleMove pop();

private:
    singleMove *array;
    int length;
    int start;
};
#endif //SURAKARTA_ZERO_ARRAYLIST_H
