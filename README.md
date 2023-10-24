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
