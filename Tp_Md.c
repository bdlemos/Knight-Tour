#include <stdio.h>

#define SIZE 8

// Definindo as variaveis globais
int condition = 0;
int rep = 0;
int retrocessos = 0;
int move_count = 0;
int board[SIZE][SIZE];
int moves_done[2][SIZE * SIZE];
int moves[2][8] = {
    {-1, -2, -2, -1, 1 ,2, 2, 1}, 
    {2, 1, -1, -2, -2, -1, 1, 2}
};

// Declaração de funçoes
// Funçoes M1 a M8 sao responsaveis por verificar se o movimento eh possivel
//int possible moves(int i, int j);
int M1(int i, int j);
int M2(int i, int j);
int M3(int i, int j);
int M4(int i, int j);
int M5(int i, int j);
int M6(int i, int j);
int M7(int i, int j);
int M8(int i, int j);
void add_move(int i, int j);
void remove_move(int i, int j);
void possible_moves(int i, int j);


int main(){
    
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;
    
    add_move(7,7);
    possible_moves(0,0);
    printf("O numero de casas visitadas foi %d \nO numero de movimentos retrocedidos foi %d\n", rep, retrocessos);
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE ; j++){
            if(board[i][j] < 10){
                printf("0%d ", board[i][j]);
            }else{
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

int M1(int i, int j){
    if(j + 2 < SIZE && i - 1 >= 0){
        if (board[i - 1][j + 2] == 0 ){
            return 1;
        }
    }
    return 0;
}

int M2(int i, int j){
    if(j + 1 < SIZE && i - 2 >= 0){
        if (board[i - 2][j + 1] == 0 ){
            return 1;
        }
    }
    return 0;
}

int M3(int i, int j){
    if(j - 1 >= 0 && i - 2 >= 0){
        if (board[i - 2][j - 1] == 0 ){
            return 1;
        }
    }
    return 0;
}

int M4(int i, int j){
    if(j - 2 >= 0 && i - 1 >= 0){
        if (board[i - 1][j - 2] == 0 ){
            return 1;
        }
    }
    return 0;
}

int M5(int i, int j){
    if(j - 2 >= 0 && i + 1 < SIZE){
        if (board[i + 1][j - 2] == 0 ){
            return 1;
        }
    }
    return 0;
}

int M6(int i, int j){
    if(j - 1 >= 0 && i + 2 < SIZE){
        if (board[i + 2][j - 1] == 0 ){
            return 1;
        }
    }
    return 0;
}

int M7(int i, int j){
    if(j + 1 < SIZE && i + 2 < SIZE){
        if (board[i + 2][j + 1] == 0 ){
            return 1;
        }
    }
    return 0;
}

int M8(int i, int j){
    if(j + 2 < SIZE && i + 1 < SIZE){
        if (board[i + 1][j + 2] == 0 ){
            return 1;
        }
    }
    return 0;
}

void add_move(int i, int j){
    board[i][j] = move_count + 1;
    moves[0][move_count] = i;
    moves[1][move_count] = j;
    move_count++;
}

void remove_move(int i, int j){
    retrocessos++;
    board[i][j] = 0;
    moves[0][move_count] = 0;
    moves[1][move_count] = 0;
    move_count--;
}

void possible_moves(int i, int j){
    rep++;
    if (move_count == SIZE * SIZE)
        condition = 1; 
    if(M1(i, j) && !condition){
        add_move(i - 1, j + 2);
        possible_moves(i - 1, j + 2);
    }
    if(M2(i, j) && !condition){
        add_move(i - 2, j + 1);
        possible_moves(i - 2, j + 1);
    }
    if(M3(i, j) && !condition){
        add_move(i - 2, j - 1);
        possible_moves(i - 2, j - 1);
    }
    if(M4(i, j) && !condition){
        add_move(i - 1, j - 2);
        possible_moves(i - 1, j - 2);
    }
    if(M5(i, j) && !condition){
        add_move(i + 1, j - 2);
        possible_moves(i + 1, j - 2);
    }
    if(M6(i, j) && !condition){
        add_move(i + 2, j - 1);
        possible_moves(i + 2, j - 1);
    }
    if(M7(i, j) && !condition){
        add_move(i + 2, j + 1);
        possible_moves(i + 2, j + 1);
    }
    if(M8(i, j) && !condition){
        add_move(i + 1, j + 2);
        possible_moves(i + 1, j + 2);
    }
    if (!condition)
        remove_move(i,j);
    return;
}