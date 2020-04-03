//
// Created by Blue Sky on 3/31/20.
//

#ifndef SURAKARTA_ZERO_EVALUATOR_H
#define SURAKARTA_ZERO_EVALUATOR_H
#include <iostream>
#include "basic.h"
int Evaluate(int chessboard_test[][6],int who_test);
int count(int chessboard_test[][6]);
int position_value(int chessboard_test[][6]);
int greenpotential(int chessboard_test[][6]);
int arc_count(int chessboard_test[][6]);
int anotherMark(int chessboard_test[][6]);
int Evaluate_test(int chessboard_test[][6],int who_test);
#endif //SURAKARTA_ZERO_EVALUATOR_H
