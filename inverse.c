#include <stdio.h>
#include <omp.h>

#define N 4

// Function to print a matrix
void printMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the inverse of a matrix
void inverseMatrix(double A[N][N], double A_inv[N][N]) {
    // Initialize the inverse matrix as an identity matrix
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A_inv[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Perform Gaussian elimination with back-substitution
    for (int k = 0; k < N; k++) {
        #pragma omp parallel for
        for (int i = 0; i < N; i++) {
            if (i != k) {
                double factor = A[i][k] / A[k][k];
                for (int j = 0; j < N; j++) {
                    A[i][j] -= factor * A[k][j];
                    A_inv[i][j] -= factor * A_inv[k][j];
                }
            }
        }
    }

    // Perform row operations to make the diagonal elements of A 1
    #pragma omp parallel for
    for (int k = 0; k < N; k++) {
        double factor = A[k][k];
        for (int j = 0; j < N; j++) {
            A[k][j] /= factor;
            A_inv[k][j] /= factor;
        }
    }
}

int main() {
    double A[N][N] = {
        {4.0, 3.0, 2.0, 1.0},
        {3.0, 4.0, 3.0, 2.0},
        {2.0, 3.0, 4.0, 3.0},
        {1.0, 2.0, 3.0, 4.0}
    };

    double A_inv[N][N];
    
   

    
    // Print the original matrix A before inversion
    printf("Original Matrix A:\n");
    printMatrix(A);

    // Find the inverse of the matrix
    inverseMatrix(A, A_inv);

    // Print the inverse matrix A_inv
    printf("\nInverse Matrix A_inv:\n");
    printMatrix(A_inv);

    return 0;
}
