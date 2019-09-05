#include <iostream>	// Biblioteca donde se encuentra la función cout
#include <math.h>

using namespace std;	// uso del espacio de nombre std

// declare prototype funciton
int get_number_digits(int x);
void get_each_digit(int x, int length_x, int *array);
int array_to_int(int length_x, int *array);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv){

	int unsigned a;
	int length_a;

	// get int number
	cout << "Ingresa un número entero" << endl;
	cin >> a;

	cout << "Original number: " << a << endl;

	// get number of digits in int
	length_a = get_number_digits(a);

	// create array 
	int array [length_a];

	// get digits
	get_each_digit(a, length_a, array);

	// print digits
	int shifted_number = array_to_int(length_a, array);

	cout << "Shifted number: " << shifted_number << endl;

	// check if number is palindrome
	if (a == shifted_number) {

		cout << "It's palindrome" << endl;

	}

	else {

		cout << "It's not palindrome" << endl;

	}

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

int array_to_int (int length_x, int *array) {

	int sum = 0;

	// iterate from right to left
	for (int i = 0; i < length_x; ++i) {

		// convert each digit to decimal
		sum += array[i]*pow(10, i);

	}

	return sum;

}