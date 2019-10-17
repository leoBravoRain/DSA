// .- Codifique un programa que reciba n como argumento y cree un arreglo A de n enteros.
// E5.- Genere una permutación aleatoria de n en A

#include <iostream>

using namespace std;

void fill_array(int *array, int n);
void print_array(int *array, int n);
void permutation_array (int * A, int n, int * P);

int main(int argc, char *argv[])
{

    srand(time(NULL));

    // get dimensions
    int n = atoi(argv[1]);

    // create arrays
    int *A = new int [n];
    int *P = new int [n];

    // fill array
    fill_array(A, n);

    // permutation
    permutation_array(A, n, P);

    // print array
    print_array(A, n);
    print_array(P, n);

    return 0;
}

bool is_in(int value, int * array, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (value == array[i])
        {
            return true;
        }
    }

    return false;
}

void permutation_array (int * A, int n, int * P)
{
    int *aux = new int [n];
    int random_index = 0;

    // fill aux with -1
    for (int i = 0; i < n; ++i) 
    {
        aux[i] = -1;
    }

    // iterate through array A
    for (int i = 0; i < n; ++i)
    {
        // choose random index
        random_index = rand() % n;

        // if random index is already selected
        while (is_in(random_index, aux, n))
        {
            // choose another
            random_index = rand() % n;
        }
        // add random index to auxialiar array
        aux[i] = random_index;

        // assign random index value to i-th element of permutaiton array
        P[i] = A[random_index];
    }
}

void fill_array(int *array, int n)
{
    // fill array
    for (int i = 0; i < n; ++i)
    {
        array[i] = i;
    }
}

void print_array(int *array, int n)
{
    if (n < 5){

        for (int i = 0; i < n; ++i)
        {
            printf("%i ", array[i]);
        }
        printf("\n");

    }
}