// E1.- Codifique un programa que reciba n, c y m como argumentos y cree las matrices A de n x c y B de
// c x m con enteros aleatorios en el intervalo [-99..99]. Luego, en una función, realice la multiplicación y
// déjela en C de n x m.
// #include <cstdlib>
#include <iostream>

#define MIN -99
#define MAX 100

using namespace std;

void multiplicar(int *A, int *B, int *C, int m, int c, int n);
void fill_array(int **array, int n, int m);
void print_array(int **array, int n, int m);
void multiply_bidimensional_arrays(int **A, int **B, int **C, int m, int c, int n);

int main(int argc, char *argv[])
{

    srand(time(NULL));

    // get dimensions
    int n = atoi(argv[1]);
    int c = atoi(argv[2]);
    int m = atoi(argv[3]);

    // create arrays
    int **A = new int *[n];
    int **B = new int *[c];
    int **C = new int *[n];
    // fill array
    fill_array(A, n, c);
    fill_array(B, c, m);
    fill_array(C, n, m);

    // print array
    print_array(A, n, c);
    print_array(B, c, m);
    print_array(C, n, m);

    multiply_bidimensional_arrays(A, B, C, m, c, n);

    // print array
    // print_array(A, n, c);
    // print_array(B, c, m);
    print_array(C, n, m);
    // }
    return 0;
}

void fill_array(int **array, int n, int m)
{
    // fill array
    for (int i = 0; i < n; ++i)
    {
        array[i] = new int[n];
        for (int j = 0; j < m; ++j)
        {
            array[i][j] = MIN + rand() % (MAX - MIN);
        }
    }
}

void print_array(int **array, int n, int m)
{
    if (n < 5 && m < 5){

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                printf("%i ", array[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    }
}

void multiply_bidimensional_arrays(int **A, int **B, int **C, int m, int c, int n)
{
    // iterate through rows of A
    for (int i = 0; i < n; i++)
    {
        // iterate through columns of B
        for (int j = 0; j < m; j++)
        {
            // initialize C value to 0
            C[i][j] = 0;

            // iterate through each column and row
            for (int k = 0; k < c; k++)
            {
                // assign value
                C[i][j] += A[i][k] * B[k][j];
                // printf("%i ", A[i][k] * B[k][j]);
            }
        }
    }
}