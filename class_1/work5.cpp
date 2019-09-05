#include <iostream>

using namespace std;	// uso del espacio de nombre std

// declare prototype funciton
int get_bynary_number_digits(int x);
// void get_each_digit(int x, int length_x, int *array);
// void print_digits(int length_x, int *array);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv){

	int x;


	// Check if it's int and positive
	cout << "Ingrese un número entero" << endl;
	cin >> x;

	int length_x_binary = get_bynary_number_digits(x);

	cout << length_x_binary << endl;
	
	int array [length_x_binary];

	int count = 0;

	while (x > 0) {

		array[count] = x % 2;
		// x%2
		x /= 2;

		count += 1;

	}

	cout << "Binary number: " << endl;

	for (int i = length_x_binary - 1; i >= 0; i--) {

		cout << array[i];

	}

	cout << endl;

	// return value
	return EXIT_SUCCESS;
}

// get number of digits of int
int get_bynary_number_digits (int x){

	// initial length
	int length = 0;

	// counting digit length
	while (x > 0) {

		x /= 2;
		length += 1;

	}

	return length;

}

// // get array of each digit in number x
// void get_each_digit (int x, int length_x, int *array){

// 	// iterate though each digit in x
//     // for (int i = 0; i < length_x; i++)
//     for (int i = length_x -1; i >= 0; --i)
//      {

//      	// get last digit
//      	array[i] = x % 10;

//      	// remove last digit
//      	x /= 10;

//      	// cout << array[i] << endl;
                             
//      }

// }

// void print_digits (int length_x, int *array) {

// 	cout << "Printing right to left:" << endl;

// 	// printing right to left
// 	for (int i = length_x - 1; i >= 0; --i) {

// 		cout << array[i];

// 	}

// 	cout << endl;

// }