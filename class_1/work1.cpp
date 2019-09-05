#include <iostream>	// Biblioteca donde se encuentra la función cout

using namespace std;	// uso del espacio de nombre std

// declare prototype funciton
void sorter_order(int a, int b, int c);
void print_numbers(int first, int second, int third);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv){

	int a, b, c;

	cout << "Ingresa un número" << endl;
	cin >> a;

	cout << "Ingresa un número" << endl;
	cin >> b;

	cout << "Ingresa un número" << endl;
	cin >> c;

	sorter_order(a, b, c);

	// if(argc != 4){

	// 	cout << "Error. It mus to be executde as ./prog" << endl;

	// 	exit(EXIT_FAILURE);

	// } 

	return EXIT_SUCCESS;
}

void print_numbers(int first, int second, int third) {

	cout << "Has ingresado " << first << ", " << second << ", " << third << endl;

}

void sorter_order(int a, int b, int c) {

	// Decision tree
	if(a < b) {

		if(b < c) {

			print_numbers(a, b, c);

		}
		else {

			if(a < c) {

				print_numbers(a, c, b);

			}

			else {

				print_numbers(c, a, b);

			}

		}

	}

	else {

		if(a < c) {

			print_numbers(b, a, c);

		}

		else {

			if(b < c) {

				print_numbers(b, c, a);

			}

			else {

				print_numbers(c, b, a);

			}

		}

	}

}