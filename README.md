# Parallel-Prog

1)Sum of Array<br>
The #pragma omp critical directive ensures that only one thread at a time can update the global sum variable to avoid data
races and maintain correctness.<br>The reduction(+:sum) clause indicates that the variable sum should be combined using the + operator when the parallel threads finish their work.<br>
'#pragma omp parallel' is used to create a parallel region in your code, allowing multiple threads to execute a block of code concurrently

2)LU decomposition<br>
The outer loop, represented by the variable k, iterates over the columns of the matrix A. It ranges from 0 to N - 1, where N is the size of the square matrix. This loop is responsible for selecting the current pivot element.<br>
The #pragma omp parallel parallelizes the loop that immediately follows it. In this case, the loop over i is parallelized, and multiple threads will work on different rows of the matrix in parallel.<br>
Inside the inner loop, the code performs normalization by dividing the current element in row i by the pivot element A[k][k]. This step ensures that the pivot element becomes 1, which is a characteristic of the lower triangular matrix in the LU decomposition.<br>
After normalization, the code proceeds to eliminate elements below and to the right of the current pivot element. The elements in the lower triangular matrix L and the upper triangular matrix U are updated simultaneously. The code subtracts the product of A[i][k] and A[k][j] from A[i][j]. This step reduces the elements below the main diagonal of the original matrix.<br>
The end result is that, at the end of this loop, the matrix A is transformed into the product of the lower triangular matrix L and the upper triangular matrix U, as per the LU decomposition algorithm.

3)Inverse of Matrix<br>
The function begins by initializing the inverse matrix A_inv as an identity matrix. An identity matrix has 1s on the main diagonal and 0s elsewhere.<br>
It then proceeds with Gaussian elimination. This is a process where the goal is to transform the original matrix A into an upper triangular matrix while simultaneously transforming the identity matrix A_inv into the inverse of the transformation applied to A.<br>

The following code is being parallelized using openMP<br>
-Normalization: The code normalizes the elements below the main diagonal by dividing each element by the current pivot element. This ensures that the pivot element becomes 1.0.<br>
-Elimination: For each row that is not the current pivot row, the code subtracts multiples of the pivot row from other rows to eliminate elements below and above the main diagonal.<br>
-Row Operations: The program performs row operations to ensure that the diagonal elements of the matrix A are all 1.0.<br>
