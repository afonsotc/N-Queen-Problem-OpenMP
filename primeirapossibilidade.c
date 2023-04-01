#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

int size;
int num_threads;
int* solution;
bool found;

void setQueen(int *board, int row, int column);
void solveParallel();
void printinfo(int *board);

int main(int argc, char *argv[]) {
    double end_time, start_time;
    size = atoi(argv[1]);
    num_threads = atoi(argv[2]);
    solution = (int *) calloc(size, sizeof(*solution));
    bool found = false;

    omp_set_dynamic(0);
    omp_set_num_threads(num_threads);

    start_time = omp_get_wtime();
    solveParallel();
    end_time = omp_get_wtime();
    printinfo(solution);

    printf("Tamanho do tabuleiro: %d\nNumero de Threads:%d\nTempo gasto:%f\n\n", size, num_threads, end_time-start_time);


    return 0;
}

void printinfo(int *board){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(j != board[i]){
                printf("0");
            } else{
                printf("1");
            }
        }
        printf("\n");
    }
    printf("\n");
}
void setQueen(int *board, int row, int column){
    int i;

    if(found){return;}

    for(i = 0; i < row; i++){
        if(board[i] == column){return;}

        if(abs(board[i] - column) == (row - i)){return;}
    }

    board[row] = column;

    if(row == (size-1)){
        found = true;
        for(i = 0; i < size;i++){
            solution[i] = board[i];
        }
    } else{
        for(i = 0; i < size; i++){
            setQueen(board, row+1, i);
        }
    }

}

void solveParallel(){

    #pragma omp parallel for
    for(int i = 0; i < size; i++){
        if(found){
        } else {
            int *board = (int *) calloc(size, sizeof(*board));
            setQueen(board, 0, i);
            free(board);
        }

    }
}
