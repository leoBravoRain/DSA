// E1.- Codifique un programa que reciba n, c y m como argumentos y cree las matrices A de n x c y B de
// c x m con enteros aleatorios en el intervalo [-99..99]. Luego, en una función, realice la multiplicación y
// déjela en C de n x m.

// E4.- Valide su resultado invocando dos veces a la función anterior, validando que la matriz devuelta es
// igual a la original (la traspuesta de la traspuesta es igual a la original).
// bool esTraspuestaTdeA(int *A, int m_a, int n_a, int *T, int m_t, int n_t);

// #include <cstdlib>
#include <iostream>

#define MIN 0
#define MAX 100

using namespace std;

void fill_array(int **array, int n, int m);
void print_array(int **array, int n, int m);
void transpose_array(int **A, int n, int m, int **T);
bool check_equal_arrays(int **A, int **B, int n, int m);

int main(int argc, char *argv[])
{

    // get dimensions
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    // create arrays
    int **A = new int *[n];
    int **T = new int *[m];
    int **B = new int *[n];

    // fill array
    fill_array(A, n, m);
    fill_array(T, m, n);
    fill_array(B, n, m);

    // transpose array
    transpose_array(A, n, m, T);
    transpose_array(T, m, n, B);

    // print array
    print_array(A, n, m);
    print_array(T, m, n);
    print_array(B, n, m);

    // test
    printf("test: %s \n", (check_equal_arrays(A, B, n, m) ? "Equals" : "Not equals"));

    return 0;
}

bool check_equal_arrays(int **A, int **B, int n, int m)
{
    bool equal = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (A[i][j] != B[i][j])
            {
                equal = false;
            }
        }
    }
    return equal;
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
    if (n < 5 && m < 5)
    {

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

void transpose_array(int **A, int n, int m, int **T)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            T[j][i] = A[i][j];
        }
    }
}