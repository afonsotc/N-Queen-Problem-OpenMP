#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int size;
int num_threads;
int num_solutions;
int* combination;

void setQueen(int *board, int row, int column, int index);
void solveParallel();

int main(int argc, char *argv[]) {
    double start_time, end_time;

    size = atoi(argv[1]);
    num_threads = atoi(argv[2]);


    omp_set_dynamic(0);
    omp_set_num_threads(num_threads);


    start_time = omp_get_wtime();

    combination = (int *) calloc(size,sizeof(*combination));
    solveParallel();

    for(int i = 0, final_sum = 0; i < size;i++){
        num_solutions += combination[i];
    }

    end_time = omp_get_wtime();


    printf("Tamanho do tabuleiro: %d\nNumero de threads(limite superior): %d\nNumero de possibilidades: %d\nTempo gasto: %f\n",size,num_threads,num_solutions, end_time - start_time);

    return 0;
}

void setQueen(int *board, int row, int column, int index){
    int i;

    for(i = 0; i < row; i++){
        if(board[i] == column){return;}

        if(abs(board[i] - column) == (row - i)){return;}
    }

    board[row] = column;

    if(row == (size-1)){
        combination[index]++;
    } else{
        for(i = 0; i < size; i++){
            setQueen(board, row+1, i, index);
        }
    }

}

void solveParallel(){
    #pragma omp parallel for
    for(int i = 0; i < size; i++){
        int *board = (int *) calloc(size, sizeof(*board));
        setQueen(board, 0, i, i);

        free(board);
    }
}
