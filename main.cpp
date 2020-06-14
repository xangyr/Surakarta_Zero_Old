#include <iostream>
#include <ctime>
#include <pthread.h>
#include "move_generator.h"
#include "test.h"
#include "search_engine.h"
#include "evaluator.h"
#include "initialization.h"
#include "game_ai.h"
#include "sort.h"
#include "chessboard.h"
#include "run.h"
#include "record.h"
#define Black_Chess 1
#define White_Chess -1
using namespace std;

int chessboard[6][6]={
        {0, -1 ,-1 ,-1, 0 ,0 },
        {-1 ,0, 0 ,0 ,0 ,0 },
        {0, 0 ,0 ,0 ,0 ,0 },
        {0, 0 ,0 ,-1 ,-1 ,0 },
        {1 ,0 ,0 ,0 ,-1 ,0 },
        {0 ,0 ,0 ,1 ,0 ,0 },
};
int who=-1;
uint64_t Hash_Board[6][6][2];
FILE *battle;
Move_List battle_record;
char path[70]="/Users/bluesky/Desktop/Surakarta_Zero/Battle/record.txt";
int main(void){
    clock_t start,end;
    start = clock();
   FILE *fp;

        fp = fopen("../resource/Data/testAlphaBeta.txt", "r");
        test_alpha_beta(fp);

    end = clock();
    cout<<"time:"<<(double)((end-start)/CLOCKS_PER_SEC);

    return 0;
}
