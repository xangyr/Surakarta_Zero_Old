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
#include "run.h"
#include "record.h"
#define Black_Chess 1
#define White_Chess -1
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
    double duration;
    clock_t start,stop;
    start=clock();
    {Hash_Board_Init(Hash_Board);

        FILE *fp;
        fp=fopen("../resource/Data/testAlphaBeta1.txt","r");
        if(fp==NULL){
            printf("open Error\n");
            return 0;
        }
        test_alpha_beta(fp);
    }
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("time=%.1lfs\n",duration);
    /*{
   FILE *fp;
   fp=fopen("/Users/bluesky/Desktop/Surakarta_Zero/Data/testMoveGenerate.txt","r");
   test(fp);
   }*/
}
