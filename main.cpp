#include <iostream>
#include <random>
#include <omp.h>
#include "matrix.h"

int main(int argc, char* argv[]) {

    const int N = 10;

    std::cout << "Size of matrix: " << N << " x " << N << std::endl;
    std::cout << "Size of float: " << sizeof(float) << std::endl;

    std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0.0, 10.0);

    int i, j;
    float** A = new float*[N];
    float** B = new float*[N];
    float** C = new float*[N];

    for (i = 0; i < N; i++) 
    { 
        A[i] = new float[N];
        B[i] = new float[N];
        C[i] = new float[N];
    }

    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            A[i][j] = dist(gen);
            B[i][j] = dist(gen);
        }
    }

    add(A, B, C, N);
    print(C, N);

    for (i = 0; i < N; i++) 
    { 
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    return 0;
}