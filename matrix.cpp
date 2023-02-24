#include <iostream>
#include <omp.h>
#include "matrix.h"

void print(float** A, const int N) 
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            std::cout << A[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void add(float** A, float** B, float** C, const int N) 
{
    #pragma omp parallel shared(A, B, C)
    {
        #pragma omp for schedule(dynamic) 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) 
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
}

void mult(float** A, float** B, float** C, const int N) 
{
    #pragma omp parallel shared(A, B, C)
    {        
        #pragma omp for schedule(dynamic)
        for (int i = 0; i < N; i++) {
            float temp;
            for (int j = 0; j < N; j++) 
            {
                temp = 0.0;
                for (int k = 0; k < N; k++)
                {
                    temp += A[i][j] * B[j][i];
                }
                C[i][j] = temp;
            }
        }
    }
}

float det(float **A, const int N)
{

    return 0.0f;
}

float trace(float **A, const int N)
{

    return 0.0f;
}

void eigenvalues(float **A, float *b, const int N)
{
}
