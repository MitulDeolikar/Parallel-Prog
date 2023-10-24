#include <stdio.h>
#include <omp.h>

#define N 4

int main() {
    double A[N][N] = {
        {4.0, 3.0, 2.0, 1.0},
        {3.0, 4.0, 3.0, 2.0},
        {2.0, 3.0, 4.0, 3.0},
        {1.0, 2.0, 3.0, 4.0}
    };

    // Perform LU decomposition in parallel
    for (int k = 0; k < N; k++) {
        #pragma omp parallel for
        for (int i = k + 1; i < N; i++) {
            A[i][k] /= A[k][k];
            for (int j = k + 1; j < N; j++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }

    // Print the lower triangular (L) and upper triangular (U) matrices
    printf("Lower Triangular Matrix (L):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                printf("%lf ", A[i][j]);
            } else if (i == j) {
                printf("1.0 "); // Diagonal elements of L are 1.0
            } else {
                printf("0.0 ");
            }
        }
        printf("\n");
    }

    printf("\nUpper Triangular Matrix (U):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i <= j) {
                printf("%lf ", A[i][j]);
            } else {
                printf("0.0 ");
            }
        }
        printf("\n");
    }

    return 0;
}
