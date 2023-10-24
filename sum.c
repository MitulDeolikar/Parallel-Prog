#include <stdio.h>
#include <omp.h>
// #include<pthread.h>

#define ARRAY_SIZE 10120

int main() {
    int array[ARRAY_SIZE];
    int sum = 0,time=0;

    // Initialize the array with some values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
   
    printf("The sum of the array elements is: %d\n", sum);
    
    return 0;
}
