#include <stdio.h>

#define SIZE 8

// Definindo as variaveis globais
int condition = 0;
int rep = 0;
int retrocessos = 0;
int move_count = 0;
int board[SIZE][SIZE];
int moves[2][SIZE * SIZE];
int Moves[2][8] = {
    {-1, -2, -2, -1, 1 ,2, 2, 1}, 
    {2, 1, -1, -2, -2, -1, 1, 2}
};

// Declaração de funçoes
// Funçoes M1 a M8 sao responsaveis por verificar se o movimento eh possivel
//Vou refatorar a logica dos movimentos
//int possible moves(int i, int j);
int IsValid(int i, int j);
void add_move(int i, int j);
void remove_move(int i, int j);
void possible_moves(int i, int j);


int main(){
    
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;
    add_move(0,0);
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

int IsValid(int i, int j){
    if ((i >= SIZE || i < 0) || (j >= SIZE || j < 0) || (board[i][j] != 0)){
        return 0;
    }
    return 1;
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

    for (int k = 0; k < 8; k++){
        if (IsValid(i + Moves[0][k], j + Moves[1][k])){
            add_move(i + Moves[0][k], j + Moves[1][k]);
            possible_moves(i + Moves[0][k], j + Moves[1][k]);
            if(condition) return;
        }

    }
    
    if (!condition)
        remove_move(i,j);
    return;
}