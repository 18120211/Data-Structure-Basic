#include "cVector.h"
#include <iostream>
using namespace std;

cVector::cVector(int n)
{
	this->size = this->capacity = n;
	this->vector = new int[n];
	vector = NULL;
	begin = end = rbegin = rend = new int;
	begin = end = rbegin = rend = NULL;
}

cVector::cVector()
{
	this->size = this->capacity = 0;
	begin = end = rbegin = rend = new int;
	begin = end = rbegin = rend = NULL;
}

int & cVector::operator[](int index)
{
	if (index < size) {
		return vector[index];
	}
}

int & cVector::at(int index)
{
	if (index < size) {
		return vector[index];
	}
}

int & cVector::front()
{
	if (!this->empty()) {
		return vector[0];
	}
}

int & cVector::back()
{
	if (!this->empty()) {
		return vector[size - 1];
	}
}

int * cVector::data()
{
	return vector;
}

int cVector::Capacity()
{
	return this->capacity;
}

int * cVector::Begin()
{
	return this->begin;
}

int * cVector::End()
{
	return this->end;
}

int * cVector::rBegin()
{
	return this->rbegin;
}

int * cVector::rEnd()
{
	return this->rend;
}

const double cVector::max_size()
{
	return 4611686018427387903;
}

bool cVector::empty()
{
	if (size == 0 || capacity == 0) return true;
	return false;
}

void cVector::resize(int newsize)
{
	while (newsize > capacity) {
		capacity *= 2;
	}
	for (int i = size; i < newsize; i++) {
		vector[i] = 0;
	}
	size = newsize;
}

void cVector::resize(int newsize, int value)
{
	while (newsize > capacity) {
		capacity *= 2;
	}
	for (int i = size; i < newsize; i++) {
		vector[i] = value;
	}
	size = newsize;
}

void cVector::shrink_to_fit()
{
	capacity = size;
}

void cVector::reverse()
{
	for (int i = 0; i < size / 2; i++) {
		std::swap(vector[i], vector[size - 1 - i]);
	}
}

int cVector::Size()
{
	return this->size;
}

void cVector::assign(int number, int value)
{
	while (number > capacity) {
		capacity *= 2;
	}
	size = number;
	for (int i = 0; i < size; i++) {
		vector[i] = value;
	}
	this->begin = &vector[0];
	this->end = &vector[size - 1];
}

void cVector::assign(int * begin, int * end)
{
	int n = end - begin + 1;
	while (n > capacity) {
		capacity *= 2;
	}
	size = n;
	int * temp = new int[n];
	for (int i = 0; i < n; i++) {
		temp[i] = *(begin + i);
	}
	delete[] vector;
	vector = temp;
	this->begin = &vector[0];
	this->end = &vector[size - 1];
}

void cVector::push_back(int data)
{
	if (size == 0 || capacity == 0) {
		size = capacity = 1;
		vector = new int[1];
		vector[0] = data;

		begin = end = rbegin = rend = &vector[0];
		return;
	}
	if (size == capacity) {
		capacity *= 2;
		int * temp = new int[capacity];
		for (int i = 0; i < size; i++) {
			temp[i] = vector[i];
		}
		delete[] vector;
		vector = temp;
		begin = rend = &vector[0];
	}
	size += 1;
	vector[size - 1] = data;
	end = rbegin = &vector[size - 1];
}

void cVector::pop_back()
{
	size -= 1;
	end = rbegin = &vector[size - 1];
}

void cVector::insert(int * it, int data)
{
	int newsize = size + 1;
	while (newsize > capacity) {
		capacity *= 2;
	}
	int * temp = new int[newsize];

	int k = 0;
	int * a = begin;
	for (int i = 0; i <= size; i++) {	
		if (a == it) {
			temp[k] = data;
			k++;
		}
		temp[k] = vector[i];
		k++;
		a++;
	}
	begin = &vector[0];
	end = &vector[newsize - 1];
	delete[] vector;
	vector = temp;
	size = newsize;
}

void cVector::insert(int * it, int number, int data)
{
	int newsize = size + number;
	while (newsize > capacity) {
		capacity *= 2;
	}
	int * temp = new int[newsize];

	int k = 0;
	int * a = begin;
	int count = 0;
	for (int i = 0; i <= size; i++) {
		if (a == it) {
			while (count < number) {
				temp[k] = data;
				k++;
				count++;
			}
		}
		temp[k] = vector[i];
		k++;
		a++;
	}
	begin = &vector[0];
	end = &vector[newsize - 1];
	delete[] vector;
	vector = temp;
	size = newsize;
}

void cVector::insert(int * it, int * pbegin, int * pend)
{
	int number = pend - pbegin + 1;
	int newsize = size  + number;
	while (newsize > capacity) {
		capacity *= 2;
	}
	int * temp = new int[newsize];

	int * a = this->begin;

	int k = 0;

	int count = 0;
	for (int i = 0; i <= size; i++) {
		if (a == it) {
			while (count < number) {
				temp[k] = *(pbegin + count);
				k++;
				count++;
			}
		}
		temp[k] = vector[i];
		k++;
		a++;
	}
	begin = &vector[0];
	end = &vector[newsize - 1];
	delete[] vector;
	vector = temp;
	size = newsize;
}

void cVector::erase(int * it)
{
	if (it - this->begin > size) {
		return;
	}
	int newsize = size - 1;
	int * a = this->begin;

	int * temp = new int[newsize];
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (a == it) {
			a++;
			continue;
		}
		temp[k] = vector[i];
		k++;
		a++;
	}
	begin = &vector[0];
	end = &vector[newsize - 1];
	delete[] vector;
	vector = temp;
	size = newsize;
}

void cVector::erase(int * pbegin, int * pend)
{
	if (pbegin < begin || pend > end || pend - pbegin + 1 > size || pend < pbegin) {
		return;
	}
	int number = pend - pbegin + 1;
	int newsize = size - number;

	int * temp = new int[newsize];
	//int temp[100];
	int k = 0;
	int * a = this->begin;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (a == pbegin) {
			a++;
			while (count < number) {
				i++;
				count++;
			}
			i--;
			continue;
		}
		temp[k] = vector[i];
		k++;
		a++;
	}
	this->begin = &temp[0];
	this->end = &temp[newsize - 1];
	delete[] vector;
	vector = temp;
	size = newsize;
}

void cVector::swap(cVector& bar)
{
	cVector temp = bar;

	bar.vector = this->data();
	bar.size = this->Size();
	bar.capacity = this->Capacity();
	bar.begin = this->Begin();
	bar.rbegin = this->rBegin();
	bar.end = this->End();
	bar.rend = this->rEnd();

	this->vector = temp.data();
	this->size = temp.Size();
	this->capacity = temp.Capacity();
	this->begin = temp.Begin();
	this->rbegin = temp.rBegin();
	this->end = temp.End();
	this->rend = temp.rEnd();
}

int * cVector::emplace(int * it, int value)
{
	this->insert(it, value);
	return it;
}

void cVector::clear()
{
	delete[] vector;
	vector = NULL;
	size = capacity = 0;

	begin = rbegin = end = rend = NULL;
}
