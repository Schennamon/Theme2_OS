#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
    Matrix matrix = dynamic_array_alloc(10, 10);
    Matrix secMatrix = dynamic_array_alloc(10, 10);

    dynamic_array_random(matrix);
    dynamic_array_random(secMatrix);
    dynamic_array_print(matrix);
    dynamic_array_print(secMatrix);
    //matrix_addition(matrix, secMatrix);
    dynamic_array_print(matrix);
    //matrix_subtraction(matrix, secMatrix);
    dynamic_array_print(matrix);
    //matrix_mult(matrix, 5);
    dynamic_array_print(matrix);
    dynamic_array_size(matrix);
    dynamic_array_insert(matrix, 6, 7, 59);
    dynamic_array_print(matrix);
    dynamic_array_recording(matrix);
    dynamic_array_reading(matrix, "matrix.txt");
    dynamic_array_print(matrix);
    //dynamic_array_resize(matrix);
    //dynamic_array_print(matrix); 

    return 0;
}
