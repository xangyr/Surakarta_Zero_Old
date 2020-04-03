//
// Created by Blue Sky on 3/31/20.
//

#ifndef SURAKARTA_ZERO_BASIC_H
#define SURAKARTA_ZERO_BASIC_H
#define Hash_table_length 2048
#define HashExact 0
#define HashAlpha 1
#define HashBeta 2
#include <iostream>

typedef struct{
    int x;
    int y;
}Position;

typedef struct{
    Position from;
    Position to;
    int value;
}Move;

typedef struct{
    Position node;
    int arc;
    int next;
    int pre;
}Orbit;

typedef  struct{
    int amount;
    int node_1;
    int node_2;
}Orbit_Index;

typedef struct{
    int chess;
    Position from;
}Rool;

typedef struct{
    Move list[100];
    int  flag;
}Move_List;

typedef struct{
    int depth;
    int minimaxplayer;
}AlphaBeta_data;

typedef struct{
    uint64_t key;
    int depth;
    int type;
    int value;
}Hash_Move;

typedef struct{
    int chessboard[6][6];
    int depth;
    int alpha;
    int beta;
    int minimaxplayer;
    int value;
}Para;

typedef struct{
    int value;
    int best_move;
}Result;

typedef struct{
    int choice_1;
    int choice_2;
}choice;

typedef struct{
    Rool *rool;
    int index;
}role;

typedef struct{
    Move_List *h;
    int who;
}Para_1;

void visualize_board();
void visualize(Move_List *h);
int judge(int chessboard_test[][6]);
int judge_test(int chessboard_test[][6]);
int max(int a,int b);
int mini(int a,int b);
#endif //SURAKARTA_ZERO_BASIC_H
