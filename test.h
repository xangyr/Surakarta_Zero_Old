//
// Created by Blue Sky on 3/31/20.
//

#ifndef SURAKARTA_ZERO_TEST_H
#define SURAKARTA_ZERO_TEST_H
#include <iostream>
#include "move_generator.h"
#include "search_engine.h"
#include "chessboard.h"

void test_alpha_beta(FILE *fp);
int * decode(long long board);
void test(FILE *fp);
void new_test(FILE *fp);
void test_MT(FILE *fp);
#endif //SURAKARTA_ZERO_TEST_H
