//
// Created by Blue Sky on 3/31/20.
//

#ifndef SURAKARTA_ZERO_TEST_H
#define SURAKARTA_ZERO_TEST_H
#include <iostream>
#include "move_generator.h"
#include "search_engine.h"
#define NO_CHESS 0
#define PINK_CHESS 1
#define BLACK_CHESS -1

void test_alpha_beta(FILE *fp);
int * decode(long long board);
void test(FILE *fp);
void new_test(FILE *fp);
void test_MT(FILE *fp);
#endif //SURAKARTA_ZERO_TEST_H
