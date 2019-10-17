#include <iostream>

using namespace std;

void print_array(int n, int *array);
void print_array_2d(int n, int m, int **array);

int main(int argc, char *argv[]) {

	// int n = atoi(argv[1]);
	// int m = atoi(argv[2]);

	// static arrays
	printf("\n \n Statics arrays \n\n");

	char array[2][2] = {

		{'x', 'o'},
		{'o', 'x'}

	};

	int numbers[] = {1, 2, 3, 4};

	char alphabet[3] = {'A', 'B', 'C'};

	char names[3][20] = {
		"leo",
		"andi",
		"berlin"
	};

	int garbage[3];

	print_array(3, garbage);

	cout << "array address: " << array << endl;
	cout << "numbers address: " << numbers << endl;
	cout << "alphabet address: " << &alphabet << endl;
	cout << "names address: " << names << endl;
	cout << "garbage address: " << &garbage << endl;

	// dynamic array

	printf("\n \n Dynamic arrays \n\n");

	// declare
	int **numbers_dynamic;

	// ask for memory
	numbers_dynamic = new int* [3];

	for(int i = 0; i < 3; ++i) {

		numbers_dynamic[i] = new int [5];

	}

	// print_array(2, numbers_dynamic);

	print_array_2d(3, 5, numbers_dynamic);

	cout << "numbers_dynamic address: " << &numbers_dynamic << endl;

	return 0;

}

void print_array(int n, int *array) {

	for(int i = 0; i < n; i++) {

		cout << array[i] << endl;

	}

}

void print_array_2d(int n, int m, int **array) {

	for(int i = 0; i < n; i++) {

		// printf("%c\n", &array[i]);
		cout << &array[i] << endl;

		for(int j = 0; j < m; ++j) {

			// cout << array[i][j] << endl;
			printf("%i ", array[i][j]);
		}

		printf("\n");

	}

}