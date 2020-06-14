//
// Created by Blue Sky on 4/3/20.
//

#include "chessboard.h"
int chessboard_value[6][6]={
        {5,20,20,20,20,5},
        {20,30,50,50,30,20},
        {20,50,40,40,50,20},
        {20,50,40,40,50,20},
        {20,30,50,50,30,20},

        {5,20,20,20,20,5}
};
int greenPotential[16]={84,91,35,35,-20,25,-25,45,-45,-45,-84,20,-91,-35,-35};
int look_for[16][2]={
        {0,2},{2,0},{0,3},{2,5},{3,0},{5,2},{5,3},{3,5},
        {1,0},{0,1},{0,4},{1,5},{4,0},{5,1},{4,5},{5,4},
};
int look_for_intersection[8][2]={
        {2,2},{2,3},{3,2},{3,3},
        {1,1},{1,4},{4,1},{4,4},
};
int look_for_arc[20][2]={
        {0,0},{0,1},{0,2},{0,3},{0,4},{0,5},
        {1,5},{2,5},{3,5},{4,5},{5,5},
        {5,4},{5,3},{5,2},{5,1},{5,0},
        {4,0},{3,0},{2,0},{1,0}
};
int look_for_anotherMark[12][2]={
        {2,2},{1,2},{2,1},
        {2,3},{1,3},{2,4},
        {3,2},{3,1},{4,2},
        {3,3},{3,4},{4,3}
};

int arcPara;
int k1=1,k2=1,k3=1,k4=1;
Chessboard::Chessboard(int who) {  //初始化棋盘，上12黑，下12白
    black=0;white=0;
    this->side = who;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(a<2)
                board[a][b]=BLACK_CHESS;
            else if(a>=4)
                board[a][b]=WHITE_CHESS;
            else
                board[a][b]=NO_CHESS;
            if(board[a][b]==BLACK_CHESS)
                black++;
            else if(board[a][b]==WHITE_CHESS)
                white++;
        }
    }
}

Chessboard::Chessboard(int who,int board[6][6]) {   //根据二维数组初始化棋盘
    black=0;white=0;
    this->side = who;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            this->board[a][b] = board[a][b];
            if(board[a][b]==BLACK_CHESS)
                black++;
            else if(board[a][b]==WHITE_CHESS)
                white++;
        }
    }
}

void Chessboard::print() {
    for(int  a=0;a<6;a++){
        for(int b=0;b<6;b++)
            if(board[a][b]==BLACK_CHESS)
                printf("2 ");
            else
                printf("%d ",board[a][b]);
        printf("\n");
    }
}

int Chessboard::judge(){
    int count_1=0,count_2=0;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(board[a][b]==side)
                count_1++;
            else if(board[a][b]==-side)
                count_2++;
        }
    }

    if(count_1==0)
        return 1;
    else if(count_2==0)
        return 2;
    else
        return 0;
}

void Chessboard::moveGenerate(int who)
{
    Generate_Move_Attack(who);
    for (int a=0;a<6; a++){
        for (int b=0;b<6;b++){
            if (board[a][b] == who){
                for (int c = a - 1; c <= a + 1; c++)
                    for (int d = b - 1; d <= b + 1; d++){
                        if (c< 0)
                            break;
                        if (d < 0)
                            d = 0;
                        if (c > 5)
                            break;
                        if (d > 5)
                            break;
                        if (board[c][d] == 0){
                            Move x( a, b, c, d );
                            move_array.push(x.move);
                        }
                    }
            }
        }
    }
}

void Chessboard::Generate_Move_Attack(int who){

    Rool rool[4][6];
    int  flag_index[4];
    flag_index[0]=extract_outside_rool_1(rool[0]);
    flag_index[1]=extract_outside_rool_2(rool[1]);
    flag_index[2]=extract_outside_rool_3(rool[2]);
    flag_index[3]=extract_outside_rool_4(rool[3]);

    Attack_Orbit(rool,flag_index,who);

    flag_index[0]=extract_inside_rool_1(rool[0]);
    flag_index[1]=extract_inside_rool_2(rool[1]);
    flag_index[2]=extract_inside_rool_3(rool[2]);
    flag_index[3]=extract_inside_rool_4(rool[3]);

    Attack_Orbit(rool,flag_index,who);
}
void Chessboard::Attack_Orbit(Rool rool[][6],int *flag_index,int who){
    for(int a=0;a<4;a++){
        if(flag_index[a]!=0){
            if(board[rool[a][flag_index[a]-1].from.x][rool[a][flag_index[a]-1].from.y]==who){
                int find_unnull=a+1;
                if(find_unnull>=4)
                    find_unnull=0;
                while(!flag_index[find_unnull]){
                    find_unnull++;
                    if(find_unnull>=4)
                        find_unnull=0;
                }
                if(rool[a][flag_index[a]-1].chess==rool[find_unnull][0].chess)
                {
                    if(rool[a][flag_index[a]-1].from.x==rool[find_unnull][0].from.x&&rool[a][flag_index[a]-1].from.y==rool[find_unnull][0].from.y)
                    {
                        int index=find_unnull;
                        if(flag_index[find_unnull]>=2)
                        {
                            if(rool[find_unnull][1].chess==-who){
                                Move x(rool[find_unnull][0].from.x,rool[find_unnull][0].from.y,rool[find_unnull][1].from.x,rool[find_unnull][1].from.y);
                                move_array.push(x.move);
                            }
                        }

                        index=a;
                        if(flag_index[a]>=2)
                        {
                            if(rool[a][flag_index[a]-2].chess==-who)
                            {
                                Move x(rool[a][flag_index[a]-1].from.x,rool[a][flag_index[a]-1].from.y,rool[a][flag_index[a]-2].from.x,rool[a][flag_index[a]-2].from.y);
                                move_array.push(x.move);
                            }
                        }
                    }

                }

                else {
                    Move x(rool[a][flag_index[a] - 1].from.x, rool[a][flag_index[a] - 1].from.y,
                           rool[find_unnull][0].from.x, rool[find_unnull][0].from.y);
                    move_array.push(x.move);
                }
            }
            if(board[rool[a][0].from.x][rool[a][0].from.y]==who)
            {
                int find_unnull=a-1;
                if(find_unnull<0)
                    find_unnull=3;
                while(!flag_index[find_unnull]){
                    find_unnull--;
                    if(find_unnull<0)
                        find_unnull=3;
                }
                if(rool[a][0].chess==rool[find_unnull][flag_index[find_unnull]-1].chess)
                {
                }

                else{
                    Move x(rool[a][0].from.x,rool[a][0].from.y,rool[find_unnull][flag_index[find_unnull]-1].from.x,rool[find_unnull][flag_index[find_unnull]-1].from.y);
                    move_array.push(x.move);
                }
            }
        }
    }


}

int Chessboard::extract_outside_rool_1(Rool *rool_1){

    int index=0;
    for(int a=5;a>=0;a--){
        if(board[2][a]!=0){
            rool_1[index].chess=board[2][a];
            rool_1[index].from.x=2;
            rool_1[index].from.y=a;
            index++;
        }
    }
    return index;
}
int Chessboard::extract_outside_rool_2(Rool *rool){

    int index=0;
    for(int a=0;a<6;a++){
        if(board[a][2]!=0){
            rool[index].chess=board[a][2];
            rool[index].from.x=a;
            rool[index].from.y=2;
            index++;
        }
    }
    return index;
}
int Chessboard::extract_outside_rool_3(Rool *rool){

    int index=0;
    for(int a=0;a<6;a++){
        if(board[3][a]!=0){
            rool[index].chess=board[3][a];
            rool[index].from.x=3;
            rool[index].from.y=a;
            index++;
        }
    }
    return index;
}
int Chessboard::extract_outside_rool_4(Rool *rool_4){

    int index=0;
    for(int a=5;a>=0;a--){
        if(board[a][3]!=0){
            rool_4[index].chess=board[a][3];
            rool_4[index].from.x=a;
            rool_4[index].from.y=3;
            index++;
        }
    }
    return index;
}
int Chessboard::extract_inside_rool_1(Rool *rool_1){

    int index=0;
    for(int a=5;a>=0;a--){
        if(board[1][a]!=0){
            rool_1[index].chess=board[1][a];
            rool_1[index].from.x=1;
            rool_1[index].from.y=a;
            index++;
        }
    }
    return index;
}
int Chessboard::extract_inside_rool_2(Rool *rool){

    int index=0;
    for(int a=0;a<6;a++){
        if(board[a][1]!=0){
            rool[index].chess=board[a][1];
            rool[index].from.x=a;
            rool[index].from.y=1;
            index++;
        }
    }
    return index;
}
int Chessboard::extract_inside_rool_3(Rool *rool){

    int index=0;
    for(int a=0;a<6;a++){
        if(board[4][a]!=0){
            rool[index].chess=board[4][a];
            rool[index].from.x=4;
            rool[index].from.y=a;
            index++;
        }
    }
    return index;
}
int Chessboard::extract_inside_rool_4(Rool *rool_4){

    int index=0;
    for(int a=5;a>=0;a--){
        if(board[a][4]!=0){
            rool_4[index].chess=board[a][4];
            rool_4[index].from.x=a;
            rool_4[index].from.y=4;
            index++;
        }
    }
    return index;
}

int Chessboard::Evaluate(int who_test){
    int test=Evaluate_test(who_test);
    if(test==9999||test==-9999)
        return test;
    int value;
    int extendVal;
    int positionVal;
    int dynamicVal;
    int potentialVal;

    extendVal=count();
    positionVal=position_value()+arc_count()*arcPara;
    dynamicVal=anotherMark();
    potentialVal=greenpotential();
    value=extendVal*k1+positionVal*k2+dynamicVal*k3+potentialVal*k3;
    if(who_test==side)
        return value;
    else
        return -value;

}

int Chessboard::count(){

    int count=0;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(board[a][b]==side)
                count++;
            else if(board[a][b]==-side)
                count--;
        }
    }
    return count;
}
int Chessboard::position_value()
{
    int value = 0;
    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            if (board[a][b] == side)
                value += chessboard_value[a][b];
            else if (board[a][b] == -side)
                value -= chessboard_value[a][b];
        }
    }
    return value;
}
int Chessboard::greenpotential(){
    int value=0;
    for(int a=0;a<=15;a+=2){
        if(board[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==side){
            if(board[look_for[a][0]][look_for[a][1]]==0&&board[look_for[a+1][0]][look_for[a+1][1]]==0)
            {value+=greenPotential[0];}
            else if(board[look_for[a][0]][look_for[a][1]]==-side&&board[look_for[a+1][0]][look_for[a+1][1]]==-side)
            {value+=greenPotential[1];}
            else if((board[look_for[a][0]][look_for[a][1]]==side||board[look_for[a+1][0]][look_for[a+1][1]]==side)&&(board[look_for[a][0]][look_for[a][1]]==0||board[look_for[a+1][0]][look_for[a+1][1]]==0))
            {value+=greenPotential[2];}
            else if(board[look_for[a][0]][look_for[a][1]]==side&&board[look_for[a+1][0]][look_for[a+1][1]]==side)
            {value+=greenPotential[4];}
        }
        else if(board[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==0)
        {  if(board[look_for[a][0]][look_for[a][1]]==side&&board[look_for[a+1][0]][look_for[a+1][1]]==side)
            {value+=greenPotential[5];}
            else if(board[look_for[a][0]][look_for[a][1]]==-side&&board[look_for[a+1][0]][look_for[a+1][1]]==-side)
            {value+=greenPotential[6];}
            else if((board[look_for[a][0]][look_for[a][1]]==side||board[look_for[a+1][0]][look_for[a+1][1]]==side)&&(board[look_for[a][0]][look_for[a][1]]==0||board[look_for[a+1][0]][look_for[a+1][1]]==0))
            { value+=greenPotential[7];}
            else if((board[look_for[a][0]][look_for[a][1]]==-side||board[look_for[a+1][0]][look_for[a+1][1]]==-side)&&(board[look_for[a][0]][look_for[a][1]]==0||board[look_for[a+1][0]][look_for[a+1][1]]==0))
            {value+=greenPotential[9];}
        }
        else if(board[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==-side){
            if(board[look_for[a][0]][look_for[a][1]]==0&&board[look_for[a+1][0]][look_for[a+1][1]]==0 )
            {value+=greenPotential[11];}
            else if(board[look_for[a][0]][look_for[a][1]]==-side&&board[look_for[a+1][0]][look_for[a+1][1]]==-side)
            {value+=greenPotential[12];}
            else if(board[look_for[a][0]][look_for[a][1]]==side&&board[look_for[a+1][0]][look_for[a+1][1]]==side)
            {value+=greenPotential[13];}
            else if((board[look_for[a][0]][look_for[a][1]]==side||board[look_for[a+1][0]][look_for[a+1][1]]==side)&&(board[look_for[a][0]][look_for[a][1]]==0||board[look_for[a+1][0]][look_for[a+1][1]]==0))
            {value+=greenPotential[14];}
        }
    }
    return value;
}
int Chessboard::arc_count(){
    int count=0;
    for(int a=0;a<20;a++)
    {
        if(board[look_for_arc[a][0]][look_for_arc[a][1]]==side)
            count++;
        else if(board[look_for_arc[a][0]][look_for_arc[a][1]]==-side)
            count--;
    }
    return count;
}
int Chessboard::anotherMark(){
    int count=0;
    for(int a=0;a<=9;a+=3){
        if(board[look_for_anotherMark[a][0]][look_for_anotherMark[a][1]]==side)
        {
            if(board[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==-side&&board[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==-side)
                count++;
        }
        else if(board[look_for_anotherMark[a][0]][look_for_anotherMark[a][1]]==-side){
            if(board[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==side&&board[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==side)
                count--;
        }
    }
    return count;
}

int Chessboard::Evaluate_test(int who_test){
    int count=0;
    int flag_1=1,flag_2=1;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(board[a][b]==who_test){
                count++;
                flag_1=0;
            }
            else if (board[a][b]==-who_test){
                count--;
                flag_2=0;
            }
        }
    }

    if(flag_1)
        return -9999;
    else if(flag_2)
        return 9999;
    return count;
}