#include <iostream>
// #include <stdlib.h>

void buble_sort(int * array, int n);
void print_array(int * array, int n);
bool test_order(int * array, int n, bool desc);
void buble_sort_desc(int * array, int n);
void insertion_sort(int * array, int n);
void insertion_sort_desc(int * array, int n);
void buble_sort_left_to_right(int * array, int n);

#define L 30

using namespace std;

int main(int argc, char * argv[])
{

    srand(time(NULL));
    
    int n = atoi(argv[1]);

    printf("array length: %i\n", n);
    int array [n];

    // for testing
    bool error = false;

    // testing 
    for (int w = 0; w < 1000; w++)
    {
        // fill array
        for (int i = 0; i < n; i++)
        {
            array[i] = rand() % (-L +2*L);
        }

        // print_array(array, n);

        // buble sort
        // buble_sort(array, n);
        // buble_sort_desc(array, n);
        // insertion_sort(array, n);
        // insertion_sort_desc(array, n);
        buble_sort_left_to_right(array, n);

        // print_array(array, n);

        // parameters: (array, n, descendent order)
        error = test_order(array, n, false);
        // if there is a error
        if (error)
        {
            printf("Error \n");
            break;
        }
        

    }

    error ? printf("Error \n") : printf("Test ok!\n");

    return 0;
}  

void print_array(int * array, int n)
{
    if (n < 5)
    {
// print array
        for (int i = 0; i < n; i++)
        {
            printf("%i ", array[i]);
        }
    }

    printf("\n");
}
// buble sort
void buble_sort(int * array, int n)
{
    // printf("buble sort !\n");

    // temp value
    int temp = 0;

    for (int j = 1; j < (n); j++)
    // for (int j = 1; j < (n); j++)
    {
        // printf("get in \n");
        for (int i = 0; i < (n - j); i++)
        // for (int i = 2; i < (n - j +1); i++)
        {
            // buble greaters values
            if (array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
            
        }
    }
}

// buble sort
// Re-implemente el algoritmo de la burbuja, haciendo ahora que los
// números burbujeen de derecha a izquierda y no de izquierda a derecha.
void buble_sort_left_to_right(int * array, int n)
{
    // printf("buble sort !\n");

    // temp value
    int temp = 0;

    for (int j = 1; j < (n); j++)
    // for (int j = 1; j < (n); j++)
    {
        // printf("get in \n");
        for (int i = n-1; i >= j; i--)
        // for (int i = 2; i < (n - j +1); i++)
        {
            // buble greaters values
            if (array[i] < array[i-1])
            {
                temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
            }
            
        }
    }
}

// buble sort
void buble_sort_desc(int * array, int n)
{
    // printf("buble sort !\n");

    // temp value
    int temp = 0;

    for (int j = 1; j < (n); j++)
    // for (int j = 1; j < (n); j++)
    {
        // printf("get in \n");
        for (int i = 0; i < (n - j); i++)
        // for (int i = 2; i < (n - j +1); i++)
        {
            // buble smaller values
            if (array[i] < array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
            
        }
    }
}

bool test_order(int * array, int n, bool desc)
{

    bool error = false;
    
    if (!desc)
    {
        for (int i = 1; i < (n); i++)
        {
            if (array[i-1] > array[i])
            {
                printf("index of error: %i\n", i);
                printf("Error with %i\n and %i\n", array[i-1]), array[i];
                error = true;
            }
        }
    }
    else {
        for (int i = 1; i < (n); i++)
        {
            if (array[i-1] < array[i])
            {
                printf("index of error: %i\n", i);
                printf("Error with %i\n and %i\n", array[i-1]), array[i];
                error = true;
            }
        }
    }

    // !error ? printf("Test ok!\n") : printf("Error in test\n");
    return error;

}

// insertion sort
void insertion_sort(int * array, int n)
{
    // prior element to i-th elemnt
    int j = 1;
    // temp for swap values
    int temp = 0;
    // iterate thorugh array
    for (int i = 1; i < n; i++)
    {
        // correct position of i element
        j = i-1;
        // store i-th value
        temp = array[i];
        // select correct position
        while (j >= 0 && temp < array[j])
        {
            // swap elements
            array[j+1] = array[j];
            j--;
        }
        // So far, j+1 is the correct position of i-th element
        
        // reallocate i-th element in the correct position
        array[j+1] = temp;

    }
}

// insertion sort
void insertion_sort_desc(int * array, int n)
{
    // prior element to i-th elemnt
    int j = 1;
    // temp for swap values
    int temp = 0;
    // iterate thorugh array
    for (int i = 1; i < n; i++)
    {
        // correct position of i element
        j = i-1;
        // store i-th value
        temp = array[i];
        // select correct position
        while (j >= 0 && temp > array[j])
        {
            // swap elements
            array[j+1] = array[j];
            j--;
        }
        // reallocate i-th element in the correct position
        array[j+1] = temp;

    }
}