#include <stdio.h>
#include <omp.h>

#define ROWS 100
#define COLS 100
#define NUM_THREADS 4

int main() {
    double array[ROWS][COLS];
    double sum = 0.0;

    // Initialize the 2D array with values 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = 2;  
        }
    }

    // Calculate the sum of the 2D array using parallel programming
    #pragma omp parallel for num_threads(NUM_THREADS) reduction(+:sum)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += array[i][j];
        }
    }

    printf("Sum of the 2D array elements: %lf\n", sum);

    return 0;
}
