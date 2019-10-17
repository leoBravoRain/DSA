#include <iostream>	// Biblioteca donde se encuentra la función cout

using namespace std;	// uso del espacio de nombre std

// declare prototype funciton
bool is_prime(int x);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv){

	// Validate arguments parameters
	if (argc != 3) {

		cout << "It must to be executed as ./prog left right" << endl;

		return EXIT_FAILURE;

	}

	// get number
	int l = atoi(argv[1]);
	int r = atoi(argv[2]);

	cout << "Prime numbers: " << endl;
	
	// iterate over each number in range
	for (int i = l; i <= r; ++i) {

		if (is_prime(i)) {

			cout << i << endl;

		}

	}

	// return value
	return EXIT_SUCCESS;
}

bool is_prime(int x) {

	bool resp = true;

	// x <= is not prime 
	if (x <= 1) {

		resp = false;

	}

	// this case is taken by the default true of resp
	// else if (x == 2) {

	// 	resp = true;

	// }

	else {

		// divide number by each smaller number
		for (int i = 2; i < x; ++i) {

			// check if it's divided by other number different from 1 and itself
			if (x % i == 0) {

				resp = false;

			}

		}

	}

	return resp;

}