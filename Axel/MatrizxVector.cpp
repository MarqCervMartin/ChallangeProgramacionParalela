#include <omp.h>

void Mult(double* A, double* x, double* y, int rows, int cols)
{
#pragma omp parallel for
for (int i = 0; i < rows; ++i){
    double sum = 0;
for (int k = 0; k < cols; ++k){
    sum += A[i*cols + k]*x[k];
}
    y[i] = sum;
}
}

int main()
{
omp_set_num_threads(3);
...
Suma(a, b, c, 100);
}
