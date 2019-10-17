#include <iostream>
#include <stdlib.h>
#define NUM 10
#include <string>
// #include <bits/stdc++.h>

using namespace std;

// structs
struct Person {

	// char name[50];
	string name;
	int age;

	struct peet {

		string name;
		string type; // cat - dog

	} peet;

	// float salary;

};

// void print_digits(int n);
// void get_position_of_p(int n, int *array, int p);
void print_array(int n, int *array);
// void binary_search(int n, int *array, int x);

int main(int argc, char *argv[]) {

	int n = 2;

	srand (time(NULL));

	Person persons [n];

	// cout << persons << endl;

	for (int i = 0; i < n; ++i)
	{

		persons[i].name = "Leo Bravo";
		persons[i].age = rand() % 100;

		persons[i].peet.name = "Berlin";
		persons[i].peet.type = "dog";
		// persons[i].age = 28;


		// cout << "Enter name" << endl;

		// // cin.get(persons[i].name, 50);
		// getline(cin, persons[i].name);

		// cout << "Enter age" << endl;

		// cin >> persons[i].age;

		// cout << "Enter salary" << endl;

		// cin >> persons[i].salary;

		// printf("age: %i\nsalary: %f\n", persons[i].age, persons[i].salary);

	}

	printf("printing persons \n");

	for (int i = 0; i < n; ++i) {


		cout << endl << "Person " << i + 1 << endl;
		cout << "Name: " << persons[i].name << endl;
		cout << "Age: " << persons[i].age << endl;
		cout << "Peet is " << persons[i].peet.name << "and is a " << persons[i].peet.type << endl;

	}

	Person person1;
	person1.name = "Berlin";
	person1.age = 1;

	Person * person_ptr;

	person_ptr = &person1;

	cout << endl << person_ptr->peet.type << endl;

	// // person_1.name = "Leo";
	// person_1.age = 28;
	// person_1.salary = 250000;



	// cout << "name: " << person_1.name << endl;


	// cin.get(person_1.name, 1);

	// for (int i = 0; i < 50; ++i)
	// {

	// 	person_1

	// }

	// srand (time(NULL));
	
	// printf("array: \n");

	// int x;

	// int n = atoi(argv[1]);

	// int *array = new int [n];

	// array[0] = rand() % NUM;

	// for (int i = 1; i < n; ++i)
	// {

	// 	array[i] = array[i - 1] + rand() % NUM;

	// }

	// print_array(n, array);

	// while (true) {

	// 	cout << "Input a number" << endl;
	// 	cin >> x;
	// 	binary_search(n, array, x);
		
	// }

	return 0;

} 

void print_array(int n, int *array)
{
	for (int i = 0; i < n; ++i)
	{

		printf("%i\n", array[i]);

	}
}

// void binary_search(int n, int *array, int x)
// {

// 	printf("binary search \n");

// 	int l, r, m, index;

// 	l = 0;
// 	r = n - 1;
// 	m = (r + l) / 2;
// 	index = -1;

// 	while (l <= r) 
// 	{

// 		printf("iteration with left %i and right %i \n", l, r);

// 		if (x < array[m])
// 		{

// 			r = m - 1 ;

// 		}

// 		else if (x > array[m])
// 		{

// 			l = m + 1;

// 		}

// 		else {

// 			index = m;

// 			break;

// 		}

// 		m = (r + l) / 2;

// 	}

// 	printf("%i is in index %i\n", x, m);

// }