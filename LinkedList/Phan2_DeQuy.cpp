#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int sumOfSquares(int n)
{
	if (n == 1) {
		return 1;
	}
	else {
		return n * n + sumOfSquares(n - 1);
	}
}

int gcd(int a, int b)
{
	if (a < b) {
		swap(a, b);
	}
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}

int fib(int n)
{
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

