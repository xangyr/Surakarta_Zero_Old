//
// Created by Blue Sky on 3/31/20.
//

#ifndef SURAKARTA_ZERO_SEARCH_ENGINE_H
#define SURAKARTA_ZERO_SEARCH_ENGINE_H
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "evaluator.h"
#include "move_generator.h"
#include "hash_table.h"
#include "initialization.h"
#include "basic.h"
#include "sort.h"
#include "record.h"
int Alpha_Beta(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p);
int Alpha_Beta_PVS(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p);
void *Alpha_Beta_pth(void  *Para);
int Alpha_Beta_Multi_Thread(int depth,int minimaxplayer,int alpha,int beta);
int Alpha_Beta_new(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p);
int Alpha_Beta_Null_Move(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p);
int Quies(int alpha, int beta,int minimaxplayer,int chessboard_test[][6]);
void AI(int depth);
#endif //SURAKARTA_ZERO_SEARCH_ENGINE_H
