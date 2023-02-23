#include <iostream>
#include <fstream>
#include <random>
#include <omp.h>
#include "matrix.h"

int main(int argc, char* argv[]) {

    const double t0 = omp_get_wtime();
    const int N = 1000;

    std::cout << "Size of matrix: " << N << " x " << N << std::endl;
    std::cout << "Size of float: " << sizeof(float) << std::endl;

    std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0.0, 10.0);

    int i, j;
    //Allocate dynamic 2D arrays, A, B, and C
    float** A = new float*[N];
    float** B = new float*[N];
    float** C = new float*[N];
    for (i = 0; i < N; i++) 
    { 
        A[i] = new float[N];
        B[i] = new float[N];
        C[i] = new float[N];
    }

    // Fill A & B with random numbers
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            A[i][j] = dist(gen);
            B[i][j] = dist(gen);
        }
    }

    const double t1 = omp_get_wtime();
    std::cout << t1 - t0 << " Arrays initialized\n"; 

    add(A, B, C, N);
    mult(C, B, A, N);


    double t2 = omp_get_wtime();
    std::cout << t2 - t1 << " Operations complete\n"; 


    // For writing larger outputs to disk
    std::ofstream f;
    f.open("output.txt");
    f.close();

    //memory cleanup
    for (i = 0; i < N; i++) 
    { 
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    return 0;
}