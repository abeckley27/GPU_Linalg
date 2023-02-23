#ifndef matrix_h
#define matrix_h

#include <iostream>

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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void mult(float** A, float** B, float** C, const int N) 
{

}


#endif