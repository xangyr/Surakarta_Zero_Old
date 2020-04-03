//
// Created by Blue Sky on 3/31/20.
//

#ifndef SURAKARTA_ZERO_HASH_TABLE_H
#define SURAKARTA_ZERO_HASH_TABLE_H
#include <iostream>
#include "basic.h"
uint64_t rand64(void);
uint64_t Hash_Key(int chessboard_test[][6]);
void Hash_store(Hash_Move *p,int type,int depth,int value,int chessboard_test[][6]);
int Hash_Hit(Hash_Move *p,int depth,int alpha,int beta,int chessboard_test[][6]);
#endif //SURAKARTA_ZERO_HASH_TABLE_H
