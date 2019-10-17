#include <iostream>
#include <stdlib.h>
#define MAX 21

using namespace std;

void print_array(int n, int *array);
void get_min_max_average(int n, int * array);
void count_repeats(int n, int* array, int *count);

int main() {

	srand (time(NULL));

	int n = 4;

	// define array
	int array [n];
	int count [n];

	// fill array
	for(int i = 0; i < n; ++i) {

		// array[i] = rand() % MAX;
		array[i] = 0;

	}

	// printf("%i\n", array[0]);

	printf("print array: \n\n");
	print_array(n, array);

	printf("\n");
// 
	get_min_max_average(n, array);

	count_repeats(n, array, count);

	print_array(n, count);

	return 0;

}

void print_array(int n, int *array) {

	for(int i = 0; i < n; i++) {

		cout << array[i] << endl;

	}

}

void get_min_max_average(int n, int * array) {

	int element;
	double average;
	int min = MAX;
	int max = 0;
	int sum = 0;

	for(int i = 0; i < n; ++i) {

		// get element
		element = array[i];

		// check if element is minimu
		if(element < min) {

			min = element;

		}

		// check max
		else if(element > max) {

			max = element;

		}


		sum += element;

	}

	printf("sum : %i\n", sum);
	// get average
	average = (double)sum/(double)n;

	// print results
	printf("Max: %i\n", max);
	printf("Min: %i\n", min);
	printf("Average: %f\n", average);

}

void count_repeats(int n, int* array, int *count) {

	// int *count [n];
	int element;
	int counter = 0;

	for(int i = 0; i < n; ++i) {

		// get element
		element = array[i];

		// check if element is repeated
		for(int j = i + 1; j < n; ++j) {

			// element is repeated
			if(element == array[j]) {

				counter ++;

			}

		}

		// store repated times of element
		count[i] = counter;
		// restart counter
		counter = 0;

	}

}