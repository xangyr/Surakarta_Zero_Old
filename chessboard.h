//
// Created by Blue Sky on 4/3/20.
//

#ifndef SURAKARTA_ZERO_CHESSBOARD_H
#define SURAKARTA_ZERO_CHESSBOARD_H
using namespace std;
#include "basic.h"
#include <queue>
#include "ArrayList.h"
//产生的走法序列查重问题


class Chessboard{
public:
    int board[6][6];
    int black;
    int white;
    int side;
    Chessboard(int who);
    Chessboard(int who,int board[6][6]);
    void print();
    int judge();
    void moveGenerate(int who);
    ArrayList move_array;
    int Evaluate(int who_test);
private:
    void Generate_Move_Attack(int who);
    void Attack_Orbit(Rool rool[][6],int *flag_index,int who);
    int extract_outside_rool_1(Rool *rool_1);
    int extract_outside_rool_2(Rool *rool);
    int extract_outside_rool_3(Rool *rool);
    int extract_outside_rool_4(Rool *rool_4);
    int extract_inside_rool_1(Rool *rool_1);
    int extract_inside_rool_2(Rool *rool);
    int extract_inside_rool_3(Rool *rool);
    int extract_inside_rool_4(Rool *rool_4);
    int count();
    int position_value();
    int greenpotential();
    int arc_count();
    int anotherMark();
    int Evaluate_test(int who_test);
};

#endif //SURAKARTA_ZERO_CHESSBOARD_H
