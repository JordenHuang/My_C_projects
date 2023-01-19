#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
// #include <windows.h>

#define UP -N
#define RIGHT 1
#define DOWN N
#define LEFT -1

#define SIZE N*N

int N=3;
int space_position = 0;



void swap(int board[], int index_a, int index_b){
    int temp;
    temp = board[index_a];
    board[index_a] = board[index_b];
    board[index_b] = temp;
    space_position = index_b;
}


void scramble(int board[]){
    srand(time(NULL));
    int swap_times = rand()%200 + 150;  // �@�}�l���ê�����
    int i, quotient, remain, direction;  // quotient�Orow, remain�Ocolumn
    for(i=0; i<swap_times; i++){
        quotient = space_position/N;
        remain = space_position%N;
        if( (quotient+1 == N || quotient-1 < 0) && (remain+1 == N || remain-1 < 0) ){  // the space is at corner
            direction = rand()%2;
            if(quotient-1 < 0  && remain-1 < 0){  // if at left up
                switch(direction){
                    case 0: swap(board, space_position, space_position+RIGHT);break;
                    case 1: swap(board, space_position, space_position+DOWN);break;
                }
            }
            else if(quotient-1 < 0  && remain+1 == N){  // at right up
                switch(direction){
                    case 0: swap(board, space_position, space_position+DOWN);break;
                    case 1: swap(board, space_position, space_position+LEFT);break;
                }
            }
            else if(quotient+1 == N  && remain+1 == N){  // at right down
                switch(direction){
                    case 0: swap(board, space_position, space_position+UP);break;
                    case 1: swap(board, space_position, space_position+LEFT);break;
                }
            }
            else{  // at left down
                switch(direction){
                    case 0: swap(board, space_position, space_position+UP);break;
                    case 1: swap(board, space_position, space_position+RIGHT);break;
                }
            }
        }
        else if(quotient+1 == N || quotient-1 < 0 || remain+1 == N || remain-1 < 0){ // the space is at edge
            direction = rand()%3;
            if(quotient-1 < 0){  // at top
                switch(direction){
                    case 0: swap(board, space_position, space_position+RIGHT);break;
                    case 1: swap(board, space_position, space_position+DOWN);break;
                    case 2: swap(board, space_position, space_position+LEFT);break;
                }
            }
            else if(remain+1 == N){  // at right
                switch(direction){
                    case 0: swap(board, space_position, space_position+DOWN);break;
                    case 1: swap(board, space_position, space_position+LEFT);break;
                    case 2: swap(board, space_position, space_position+UP);break;
                }
            }
            else if(quotient+1 == N){  // at bottom
                switch(direction){
                    case 0: swap(board, space_position, space_position+LEFT);break;
                    case 1: swap(board, space_position, space_position+UP);break;
                    case 2: swap(board, space_position, space_position+RIGHT);break;
                }
            }
            else{
                switch(direction){  // at left
                    case 0: swap(board, space_position, space_position+UP);break;
                    case 1: swap(board, space_position, space_position+RIGHT);break;
                    case 2: swap(board, space_position, space_position+DOWN);break;
                }
            }
        }
        else{  // the space is not at corner and edge
            direction = rand()%4;
            switch(direction){
                case 0: swap(board, space_position, space_position+UP);break;
                case 1: swap(board, space_position, space_position+RIGHT);break;
                case 2: swap(board, space_position, space_position+DOWN);break;
                case 3: swap(board, space_position, space_position+LEFT);break;
            }
        }
    }
}



int valid_direction(int board[], int move_direction){
    int quotient = space_position/N;
    int remain = space_position%N;
    if( (quotient+1 == N || quotient-1 < 0) && (remain+1 == N || remain-1 < 0) ){  // the space is at corner
        if(quotient-1 < 0  && remain-1 < 0){  // if at left up
            switch(move_direction){
                case 0: return 0;
                case 1: return 1;
                case 2: return 1;
                case 3: return 0;
            }
        }
        else if(quotient-1 < 0  && remain+1 == N){  // at right up
            switch(move_direction){
                case 0: return 0;
                case 1: return 0;
                case 2: return 1;
                case 3: return 1;
            }
        }
        else if(quotient+1 == N  && remain+1 == N){  // at right down
            switch(move_direction){
                case 0: return 1;
                case 1: return 0;
                case 2: return 0;
                case 3: return 1;
            }
        }
        else{  // at left down
            switch(move_direction){
                case 0: return 1;
                case 1: return 1;
                case 2: return 0;
                case 3: return 0;
            }
        }
    }
    else if(quotient+1 == N || quotient-1 < 0 || remain+1 == N || remain-1 < 0){ // the space is at edge
        if(quotient-1 < 0){  // at top
            switch(move_direction){
                case 0: return 0;
                case 1: return 1;
                case 2: return 1;
                case 3: return 1;
            }
        }
        else if(remain+1 == N){  // at right
            switch(move_direction){
                case 0: return 1;
                case 1: return 0;
                case 2: return 1;
                case 3: return 1;
            }
        }
        else if(quotient+1 == N){  // at bottom
            switch(move_direction){
                case 0: return 1;
                case 1: return 1;
                case 2: return 0;
                case 3: return 1;
            }
        }
        else{
            switch(move_direction){  // at left
                case 0: return 1;
                case 1: return 1;
                case 2: return 1;
                case 3: return 0;
            }
        }
    }
    else{  // the space is not at corner and edge
        switch(move_direction){
            case 0: return 1;  // up
            case 1: return 1;  // right
            case 2: return 1;  // down
            case 3: return 1;  // left
        }
    }
}


void user_input(int board[]){
    int move = getch();
    if(move == 27){
        printf("\nQuit");
        exit(0);
    }
    if(move == 224){
        move=getch();
        switch(move){
            case 72:
                // printf("UP");
                if( valid_direction(board, 0)==0 ) break;
                swap(board, space_position, space_position+UP);
                break;
            case 77:
                // printf("RIGHT");
                if( valid_direction(board, 1)==0 ) break;
                swap(board, space_position, space_position+RIGHT);
                break;
            case 80:
                // printf("DOWN");
                if( valid_direction(board, 2)==0 ) break;
                swap(board, space_position, space_position+DOWN);
                break;
            case 75:
                // printf("LEFT");
                if( valid_direction(board, 3)==0 ) break;
                swap(board, space_position, space_position+LEFT);
                break;
        }
    }
    else{
        switch(move){
            case 119:
                // printf("UP");
                if( valid_direction(board, 0)==0 ) break;
                swap(board, space_position, space_position+UP);
                break;

            case 100:
                // printf("RIGHT");
                if( valid_direction(board, 1)==0 ) break;
                swap(board, space_position, space_position+RIGHT);
                break;

            case 115:
                // printf("DOWN");
                if( valid_direction(board, 2)==0 ) break;
                swap(board, space_position, space_position+DOWN);
                break;

            case 97:
                // printf("LEFT");
                if( valid_direction(board, 3)==0 ) break;
                swap(board, space_position, space_position+LEFT);
                break;
        }
    }
}


int end_game(int board[], int solved_board[]){
    int i;

    for(i=0; i<SIZE; i++){
        if(board[i] != solved_board[i]){
            return 0;
        }
    }

    return 1;
}



int main(){
    printf("8 puzzla game!!\n");
    printf("Enter the side length N (N must bigger than 2): ");
    scanf("%d", &N);
    printf("Use arrow keys or WASD keys to move, ESC to quit");

    int solved_board[SIZE];
    int board[SIZE];
    int i, j, end;
    

    i = SIZE-1;
    solved_board[i] = 0;
    board[i] = 0;
    for(i=0, j=1; i<SIZE-1; i++, j++){  // ��l�ƴѽL
        solved_board[i] = j;
        board[i] = solved_board[i];
    }

    
    space_position=SIZE-1;  // ��l��space����m

    scramble(board);  // ���ôѽL

    while(1){
        printf("\x1b[2J\n");

        for(i=0, j=0; i<SIZE+N; i++){  // ��X�ѽL  // size+N �O�]���h�F���檺column
            if(i==1){
                printf("\033[H");
            }
            
            if(i%(N+1) != 0){
                if(board[j]==0){
                    printf("   ");
                }
                else{
                    printf(" %2d", board[j]);
                }
                j++;
            }
            else{
                printf("\n");
            }
        }
        printf("\n\n");
        end = end_game(board, solved_board);  // �P�_�O�_����
        if(end==1){
            printf(" SOLVED!!\n");
            break;
        }

        user_input(board);  // �ϥΪ̿�J

        printf("\x1b[H");
    }
}