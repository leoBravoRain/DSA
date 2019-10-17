#include <iostream>
#include <stdlib.h>
#define NUM 10
// #include <bits/stdc++.h>

using namespace std;

// void print_digits(int n);
// void get_position_of_p(int n, int *array, int p);
void print_array(int n, int *array);
void binary_search(int n, int *array, int x);

int main(int argc, char *argv[]) {

	srand (time(NULL));
	
	printf("array: \n");

	int x;

	int n = atoi(argv[1]);

	int *array = new int [n];

	array[0] = rand() % NUM;

	for (int i = 1; i < n; ++i)
	{

		array[i] = array[i - 1] + rand() % NUM;

	}

	print_array(n, array);

	while (true) {

		cout << "Input a number" << endl;
		cin >> x;
		binary_search(n, array, x);
		
	}

	return 0;

} 

void print_array(int n, int *array)
{
	for (int i = 0; i < n; ++i)
	{

		printf("%i\n", array[i]);

	}
}

void binary_search(int n, int *array, int x)
{

	printf("binary search \n");

	int l, r, m, index;

	l = 0;
	r = n - 1;
	m = (r + l) / 2;
	index = -1;

	while (l <= r) 
	{

		printf("iteration with left %i and right %i \n", l, r);

		if (x < array[m])
		{

			r = m - 1 ;

		}

		else if (x > array[m])
		{

			l = m + 1;

		}

		else {

			index = m;

			break;

		}

		m = (r + l) / 2;

	}

	printf("%i is in index %i\n", x, m);

}