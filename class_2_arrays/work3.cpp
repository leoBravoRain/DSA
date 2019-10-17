#include <iostream>
#include <stdlib.h>
#define  MIN 100
#define MAX 1000

using namespace std;

void print_array(int n, int *array);
void get_min_max_average(int n, int * array);
void count_repeats(int n, int* array, int *count);

int main(int argc, char *argv[]) {

	srand (time(NULL));
	
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	printf("dimensions\n");
	printf("%i\n", n);
	printf("%i\n", m);

	// int **array;

	printf("array: \n");
	int **array = new int * [n];

	// iterate array
	for(int i = 0; i < n; ++i) {

		array[i] = new int[m];

		for(int j = 0; j < m; ++j) {

			array[i][j] = MIN + rand() % (MAX - MIN); 

			printf("%i ", array[i][j]);

		}

		printf("\n");

	}

	return 0;

}