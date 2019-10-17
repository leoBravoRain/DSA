#include <iostream>
#include <stdlib.h>

#define L 30

void print_array(int n, int *array);
void buble_sort(int * array, int n);

int main(int argc, char *argv[]) {

	srand (time(NULL));

	int n = atoi(argv[1]);

	int *array ;

	array = new int [n];

	for (int i = 0; i < n; ++i) {

		// array[i] = -L + rand() % L;
		array[i] = rand() % L;

	}

	printf("original array:\n");

	print_array(n, array);

	printf("ordered array:\n");

	buble_sort(array, n);

	print_array(n, array);

	return 1;

}

void buble_sort(int * array, int n) {

	printf("buble sort\n");

	int temp;

	for (int i = 1; i < n; ++i) {

		for (int j = 2; j < (n - i + 1); ++j) {

			if (array[j - 1] > array[j]) {

				temp = array[j];

				array[j] = array[j-1];

				array[j-1] = temp;

			}

		}

	}

	// int temp;

	// for (int i = 1; i < n; ++i) {

	// 	for (int j = 2; j < (n - i + 1); ++j) {

	// 		if (array[j] < array[j - 1]) {

	// 			// printf("i: %i, j: %i\n", i, j);
	// 			temp = array[j];

	// 			array[j] = array[j - 1];

	// 			array[j-1] = temp;

	// 		}

	// 	}

	// }

}

void print_array(int n, int *array) {

	for (int i = 0; i < n; ++i) {

		printf("%i\n", array[i]);

	}

}