#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY 11

void print_array(int n, int *array);
void test_sorted_order(int n, int *array, int test_size, bool asc);
void create_array(int n, int *array);
void buble_sort(int n, int *array);
void buble_sort_descendent(int n, int *array);
void insertion_sort(int n, int *array);

int main(int argc, char *argv[])
{

    srand(time(NULL));

    int n = atoi(argv[1]);
    int test_size = atoi(argv[2]);

    int array[n];

    create_array(n, array);

    print_array(n, array);

    // buble_sort(n, array);
    insertion_sort(n, array);

    printf("Sorted order ascendent: \n");

    print_array(n, array);

    test_sorted_order(n, array, test_size, true);

    // create_array(n, array);

    // print_array(n, array);

    // // buble_sort_descendent(n, array);

    // print_array(n, array);

    // test_sorted_order(n, array, test_size, false);
}

void buble_sort_descendent(int n, int *array)
{

    int temp;

    // bubble sort
    for (int j = 2; j <= n; ++j)
    {

        for (int i = 0; i <= (n - j); ++i)

            if (array[i] < array[i + 1])
            {

                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
            }
    }
}

void insertion_sort(int n, int *array)
{
    int key;
    int j;

    for (int i = 1; i < n; ++i)
    {
        key = array[i];
        j = i - 1;

        while ((j >= 0) & (array[j] > key))
        {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = key;
    }
}

void buble_sort(int n, int *array)
{

    int temp;

    // bubble sort
    for (int j = 2; j <= n; ++j)
    {

        for (int i = 0; i <= (n - j); ++i)

            if (array[i] > array[i + 1])
            {

                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
            }
    }
}
void create_array(int n, int *array)
{

    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
    }
}

void print_array(int n, int *array)
{

    if (n < MAX_ARRAY)
    {

        for (int i = 0; i < n; ++i)
        {

            printf("%i ", array[i]);
        }

        printf("\n");
    }
}

void test_sorted_order(int n, int *array, int test_size, bool asc)
{

    bool error = false;

    printf("Starting test. \n");

    if (asc)
    {

        printf("n° test: %i \nmode: ascendent\n", test_size);

        // iteration test_size times
        for (int i = 0; i < test_size; i++)
        {

            // restart array
            create_array(n, array);

            // apply buble sort
            // buble_sort(n, array);
            insertion_sort(n, array);

            // iterate over each element in array
            for (int i = 0; i < n - 1; i++)
            {
                if (array[i] > array[i + 1])
                {

                    error = true;
                }
            }
        }
    }

    else
    {

        printf("n° test: %i \nmode: descendent\n", test_size);

        // iteration test_size times
        for (int i = 0; i < test_size; i++)
        {

            // restart array
            create_array(n, array);

            // apply buble sort
            buble_sort_descendent(n, array);

            // iterate over each element in array
            for (int i = 0; i < n - 1; i++)
            {
                if (array[i] < array[i + 1])
                {

                    error = true;
                }
            }
        }
    }

    // print test result
    error ? printf("Error in test\n") : printf("Test ok\n");
}