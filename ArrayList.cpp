//
// Created by Blue Sky on 4/4/20.
//


#include "ArrayList.h"

ArrayList::ArrayList() {
    start=0;
    length=0;
    array = (singleMove *)malloc(100*sizeof(singleMove));
}

void ArrayList::clear() {
    length=0;
    start=0;
}

bool ArrayList::unempty(){
    if(size())
        return true;
    else
        return false;
};

int ArrayList::size() {
    return length-start;
}

void ArrayList::push(singleMove X){
    for(int a=start;a<length;a++)
    {
        if(array[a].from.x == X.from.x && array[a].from.y == X.from.y && array[a].to.x == X.to.x && array[a].to.y == X.to.y)
            return;
    }
    array[length++]=X;
};

singleMove ArrayList::pop() {
    return array[start++];
}

