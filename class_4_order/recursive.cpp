#include <iostream>

int fibonacci(int n);
int factorial(int n);
bool palindrome(char * string, int l, int r);

using namespace std;

int main(int argc, char *argv[])
{
    // get n
    int n = atoi(argv[1]);
    // string for palindrome
    int m = 5;
    // char string [m] = {'s', 'o', 'l', 'o'};
    char string [m] = {'l', 'e', 'v', 'e', 'l'};
    // factorial
    cout << factorial(n) << endl;
    // fibonacci
    cout << fibonacci(n) << endl;
    // palindrome
    cout << palindrome(string, 0, m-1) << endl;
    // return
    return 0;
}

// recursive form of factorial
int factorial(int n)
{
    printf("fact of: %i\n", n);
    // base case
    if (n < 2)
    {
        return 1;
    }
    // recursive case
    else
    {
        return n * factorial(n - 1);
    }
}
// recursive form of fibonacci
int fibonacci(int n)
{
    printf("fib of : %i\n", n);
    // base case
    if (n < 2)
    {
        return 1;
    }
    // if n > 1
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// palindrome recursive form
bool palindrome(char *string, int l, int r)
{
    printf("Palindrome call with (l, r): (%i, %i)\n", l, r);
    // base case
    if (l >= r)
    {
        printf("base case of palindrome. It's palindrome!\n");
        return true;
    }
    // recursive case
    else
    {
        // compare if char are equals
        printf("Comparing %c with %c\n", string[l], string[r]);
        if (string[l] == string[r])
        {
            return palindrome(string, l + 1, r - 1);
        }
        // if char are differents
        else
        {
            printf("It's NOT palindrome\n");
            return false;
        }
    }
}