#ifndef matrix_h
#define matrix_h

void print(float** A, const int N);
void add(float** A, float** B, float** C, const int N) ;
void mult(float** A, float** B, float** C, const int N) ;

float det(float** A, const int N);
float trace(float** A, const int N);

void eigenvalues(float** A, float* b, const int N);


#endif