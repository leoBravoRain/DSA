#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

void quick_sort(int * array, int l, int r);
void print_array(int * array, int n);
void fill_array (int * array, int n);
void test_order_asc(int * array, int n);
// compare function for sort
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

using namespace std;

int main(int argc, char * argv[])
{
    srand(time(NULL));
    // length array
    // int n = 10;
    int n = atoi(argv[1]);
    // array
    int array [n];
    // execution time measurement
    clock_t begin, end;
    
    // Own quicksort implementation

    // fill array
    fill_array(array, n);
    // print array
    print_array(array, n);
    // start time measurement
    begin = clock(); 
    // quicksort
    quick_sort(array, 0, n);
    // finish time measurement
    end = clock();
    // printf("Execution time own quicksort: %f\n", double(end-start));
    cout << "Execution time own quicksort: " << (double(end-begin)/CLOCKS_PER_SEC)*1000 << endl;
    // print array
    print_array(array, n);
    // testing
    test_order_asc(array, n);

    // C++ quicksort implementation

    // fill array again
    fill_array(array, n);
    // print array
    print_array(array, n);
    // start time measurement
    begin = clock();
    // quicksort from STL
    qsort(array, n, sizeof(int), compare);
    // finish time measurement
    end = clock();
    cout << "Execution time own quicksort: " << (double(end-begin)/CLOCKS_PER_SEC)*1000 << endl;
    // print array
    print_array(array, n);
    // testing
    test_order_asc(array, n);

    // C++ sort(b) implementation

    // fill array
    fill_array(array, n);
    // print array
    print_array(array, n);
    // start time measurement
    begin = clock();
    // sort of C++
    std::sort(array, array + n);
    // finish time measurement
    end = clock();
    cout << "Execution time own quicksort: " << (double(end-begin)/CLOCKS_PER_SEC)*1000 << endl;
    // print array
    print_array(array, n);
    // testing
    test_order_asc(array, n);

    // finish program

    // return
    return 1;
}

// testing
void test_order_asc(int * array, int n)
{
    bool error = false;
    for (int i = 0; i < n-1; i++)
    {
        if (array[i] > array[i+1])
        {
            error = true;
            break;
        }
    }
    error ? printf("Error in test!\n") : printf("Test ok\n");
}

// random initialization
void fill_array (int * array, int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = rand()%100;
    }
}

// return parition of array (quicksort)
int partition(int * array, int l, int r)
{
    // index of pivot
    int p = l;
    // pivot value
    int pv = array[p];
    // to swap
    int temp = 0;
    // iterate over array
    for (int i = l+1; i <= r; i++)
    {
        // if i-th element is smaller than pivot
        if (array[i] < pv)
        {
            // swap
            temp = array[i];
            array[i] = array[p+1];
            array[p+1] = temp;
            // update pivot index
            p++;
        }
    }
    // Once it finds pivot correct position, so swap pivot
    // swap
    temp = array[l];
    array[l] = array[p];
    array[p] = temp;
    // return pivot index
    return p;
}

// quicksort recursive
void quick_sort(int * array, int l, int r)
{
    // printf("quicksort from [%i, %i]\n", l, r);
    // partition index
    int p = 0;
    // recurisve form
    if (l < r)
    {
        // create partition
        p = partition(array, l, r);
        // printf("partition: %i\n", p);
        // print_array(array, 10);
        // recursive quicksort to left side
        quick_sort(array, l, p-1);
        // recursive quicksort to right side
        quick_sort(array, p+1, r);
    }
    // // base case
    // else {
    //     return 
    // }
}

// print array
void print_array(int * array, int n)
{
    if(n < 10)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%i ", array[i]);
        }
        printf("\n");
    }
}

