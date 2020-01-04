#include <iostream>
#include <stdlib.h>
using namespace std;

void inputArray(int *&a, int &n)
{
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void dellocateArray(int* &a)
{
	delete(a);
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int findMin(int* a, int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

int findMaxModulus(int* a, int n)
{
	int maxABS = abs(a[0]);
	for (int i = 1; i < n; i++) {
		if (abs(a[i]) < maxABS) {
			maxABS = abs(a[i]);
		}
	}
	return maxABS;
}

bool isAscending(int* a, int n)
{
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] < a[i]) {
			return false;
		}
	}
	return true;
}

int sumofArray(int* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

bool isPrime(int n)
{
	if (n == 1 || n == 0) {
		return false;
	}
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int countPrime(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(n)) {
			count++;
		}
	}
	return count;
}

void reverseArray(int* &a, int n)
{
	for (int i = 0; i <= n / 2; i++) {
		swap(a[i], a[n - i - 1]);
	}
}

int LinearSearch(int* a, int n, int key)
{
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}

int sentinelLinearSearch(int* a, int n, int key)
{
	return 1;

}

int BinarySearch(int* a, int n, int key)
{
	int left = 0, right = n - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] > key) {
			right = mid - 1;
		}
		else if (a[mid] < key){
			left = mid + 1;
		}
	}
	return -1;
	
}

int recursiveBinarySearch(int* a, int left, int right, int key)
{
	int pivot = (left + right) / 2;
	if (key == a[pivot]) {
		return pivot;
	}
	else if (key > a[pivot]) {
		return recursiveBinarySearch(a, pivot + 1, right, key);
	}
	else {
		return recursiveBinarySearch(a, left, pivot - 1, key);
	}
}

