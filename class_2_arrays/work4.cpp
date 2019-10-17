#include <iostream>
#include <stdlib.h>
#define  MIN 10
#define MAX 99
#include <bits/stdc++.h>

using namespace std;

void print_digits(int n);
void get_position_of_p(int n, int *array, int p);
void print_array(int n, int *array);

int main(int argc, char *argv[]) {

	srand (time(NULL));
	
	int n, p;

	cout << "Write a number: " << endl;
	cin >> n;
	// int n = atoi(argv[1]);
	// int m = atoi(argv[2]);

	printf("dimensions\n");
	printf("%i\n", n);
	// printf("%i\n", m);

	// int **array;

	printf("array: \n");

	int *array = new int [n];

	// iterate array
	for(int i = 0; i < n; ++i) {

		array[i] = MIN + rand() % (MAX - MIN); 

		printf("%i ", array[i]);

	}

	printf("\n");

	printf("print digits \n");

	// print digits array
	for(int i = 0; i < n; ++i) {

		print_digits(array[i]);

	}

	// take a number from user
	cout << "Write a position from 0 to " << n-1 << endl;
	cin >> p;

	get_position_of_p(n, array, p);

	return 0;

}

void print_digits(int n) {

	int digits [2];

	for(int i = 1; i >= 0; --i) {

		// get last digit
		digits[i] = n % 10;

		// remove last digit
		n /= 10;

	}	

	for (int i = 0; i < 2; ++i)
	{

		printf("--%i", digits[i]);

	}

	printf("\n");

}

int binary_search(int n, int *array, int element) 
{

	int l = 0;
	int r = n-1;
	int m;
	int index = -1;

	do {

		// define middle of array
		m = (r - l) / 2;

		// printf("m value: %i\n", m);

		// check if element is smaller thant m-element
		if(element < array[m]) {

			r = m - 1;

		}

		else if (element > array[m]) {

			l = m + 1;

		}

		// if array[m] == element
 		else {

			// get out from bucle
 			index = m;
			break;

		}

	} while (l >= r);

	return index;

}

void print_array(int n, int *array) {

	for(int i = 0; i < n; i++) {

		cout << array[i] << " ";

	}

	cout << endl;

}

void get_position_of_p(int n, int *array, int p)
{

	printf("The digit %i in array is: %i\n", p, array[p]);

	int copy_array [n];

	for (int i = 0; i < n; ++i)
	{
		copy_array[i] = array[i];	
	}

	// sorted order
	sort(copy_array, copy_array + n);

	printf("Printing sorted array\n");

	print_array(n, copy_array);

	// find index of value
	int k = binary_search(n, copy_array, array[p]);

	printf("The index of %i element in array would be: %i\n", array[p], k);

}