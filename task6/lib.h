#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int **A;
    size_t N;
    size_t M;
};

void dynamic_array_random(Matrix matrix){
    for(int i = 0; i < matrix.N; i++) {
        for(int j = 0; j < matrix.M; j++) {
            matrix.A[i][j] = rand() % 9;
        }
    }
}


void dynamic_array_print(Matrix matrix)
{
    for(int i = 0; i < matrix.N; i++) {
        for(int j = 0; j < matrix.M; j++) {
            printf("%*d", 5, matrix.A[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}

Matrix dynamic_array_alloc(size_t N, size_t M)
{
    int **A = (int **)malloc(N*sizeof(int *));
    for(int i = 0; i < N; i++) {
        A[i] = (int *)malloc(M*sizeof(int));
    }

    Matrix matrix;

    matrix.N = N;
    matrix.M = M;
    matrix.A = A;

    return matrix;
}

void dynamic_array_free(Matrix matrix)
{
    for(int i = 0; i < matrix.N; i++) {
        free(matrix.A[i]);
    }
    free(matrix.A);
}

Matrix dynamic_array_resize(Matrix matrix){
    matrix.A = (int **)realloc(matrix.A, matrix.N * sizeof(int *));

    for(int i = 0; i < matrix.N; i++) {
        matrix.A[i] = (int *)realloc(matrix.A, matrix.M * sizeof(int));
    }

    return matrix;
}

Matrix dynamic_array_insert(Matrix matrix, int N, int M, int num){
    matrix.A[N][M] = num;

    return matrix;
}

void dynamic_array_size(Matrix matrix){
    printf("Columns = %zd\nRows = %zd\n", matrix.M, matrix.N);
}

void dynamic_array_recording(Matrix matrix){
    FILE *myFile;
    myFile = fopen("matrix.txt", "w");

    if(myFile != NULL){
        for(int i = 0; i < matrix.N; i++){
            for(int j = 0; j < matrix.M; j++){
                fprintf(myFile, "%d ", matrix.A[i][j]);
            }
            fprintf(myFile, "\n");
        }
    }

    fclose(myFile);
}

void dynamic_array_reading(Matrix matrix, char *str){
    int i = 0;
    int j = 0;
    int temp = 0;
    FILE *file = fopen(str, "r");

    while (fscanf(file, "%d", &temp) != EOF){
        matrix.A[i][j] = temp;
        j++;

        if(j >= matrix.M){
            j = 0;
            i++;
        }
    }
}

void matrix_addition(Matrix matrix, Matrix secMatrix){
    for(int i = 0; i < secMatrix.N; i++){
        for(int j = 0; j < secMatrix.M; j++){
            matrix.A[i][j] += secMatrix.A[i][j];
        }
    }
}

void matrix_subtraction(Matrix matrix, Matrix secMatrix){
    for(int i = 0; i < secMatrix.N; i++){
        for(int j = 0; j < secMatrix.M; j++){
            matrix.A[i][j] -= secMatrix.A[i][j];
        }
    }
}

void matrix_mult(Matrix matrix, int num){
    for(int i = 0; i < matrix.N; i++){
        for(int j = 0; j < matrix.M; j++){
            matrix.A[i][j] *= num;
        }
    }
}