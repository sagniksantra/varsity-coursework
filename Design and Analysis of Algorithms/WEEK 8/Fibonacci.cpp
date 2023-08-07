#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    int fib1 = 0, fib2 = 1, fib;
    cout << "Fibonacci series up to " << n << ": ";
    cout << fib1 << " " << fib2 << " ";
	
    for (int i = 2; fib <=n; i++) 
	{
        fib = fib1 + fib2;
        if(fib<=n)cout << fib << " ";
        fib1 = fib2;
        fib2 = fib;
    }

    return 0;
}
