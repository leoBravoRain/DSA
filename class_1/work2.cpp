#include <iostream>	// Biblioteca donde se encuentra la función cout

using namespace std;	// uso del espacio de nombre std

// declare prototype funciton
int get_number_digits(int x);
void get_each_digit(int x, int length_x, int *array);
void print_digits(int length_x, int *array);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv){

	int a;
	int length_a;

	// Check if it's int and positive
	do {

		cout << "Ingresa un número positivo" << endl;
		cin >> a;

	}while (a <= 0);

	// get number of digits in int
	length_a = get_number_digits(a);

	// create array 
	int array [length_a];

	// get digits
	get_each_digit(a, length_a, array);

	// print digits
	print_digits(length_a, array);

	// return value
	return EXIT_SUCCESS;
}

// get number of digits of int
int get_number_digits (int x){

	// initial length
	int length = 0;

	// counting digit length
	while (x > 0) {

		x /= 10;
		length += 1;

	}

	return length;

}

// get array of each digit in number x
void get_each_digit (int x, int length_x, int *array){

	// iterate though each digit in x
    // for (int i = 0; i < length_x; i++)
    for (int i = length_x -1; i >= 0; --i)
     {

     	// get last digit
     	array[i] = x % 10;

     	// remove last digit
     	x /= 10;

     	// cout << array[i] << endl;
                             
     }

}

void print_digits (int length_x, int *array) {

	cout << "Printing right to left" << endl;

	// printing right to left
	for (int i = length_x - 1; i >= 0; --i) {

		cout << array[i] << endl;

	}

	cout << "Printing left to right" << endl;

	// printing left to right
	for (int i = 0; i < length_x; ++i) {

		cout << array[i] << endl;

	}


}