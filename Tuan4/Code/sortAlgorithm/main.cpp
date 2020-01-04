#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;


void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void InsertSort(int arr[], int n)
{
	int t, j;
	for (int i = 1; i < n; i++) {
		j = i - 1;
		t = arr[i];
		while (j >= 0 && t < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = t;
	}
}

int binarySearch(int arr[], int item, int low, int high)
{
	if (high <= low)
		return (item > arr[low]) ? (low + 1) : low;
	int mid = (low + high) / 2;
	if (item == arr[mid])
		return mid + 1;
	if (item > arr[mid])
		return binarySearch(arr, item, mid + 1, high);
	return binarySearch(arr, item, low, mid - 1);
}

void binaryInsertionSort(int arr[], int n)
{
	int i, loc, j, k, selected;
	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = arr[i];
		//Sử dụng binarySearch để tìm phần tử thích hợp
		loc = binarySearch(arr, selected, 0, j);
		while (j >= loc)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = selected;
	}
}

void bubblesort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				//swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void ShakerSort(int arr[], int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				//swap(arr[i], arr[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				//swap(arr[i], arr[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

int shellSort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i += 1) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return 0;
}

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		//swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		//swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1], *R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}


void quickSort(int a[], int left, int right) {

	int middle = left + (right - left) / 2;
	int pivot = a[middle];
	int i = left, j = right;

	while (i <= j) {
		while (a[i] < pivot) {
			i++;
		}

		while (a[j] > pivot) {
			j--;
		}

		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			//swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(a, left, j);
	if (right > i)
		quickSort(a, i, right);
}



void countSort(char arr[])
{
	char *output = new char[strlen(arr)];
	int *count = new int[255 + 1], i;
	memset(count, 0, sizeof(count));

	for (i = 0; arr[i]; ++i)
		++count[arr[i]];
	for (i = 1; i <= 255; ++i)
		count[i] += count[i - 1];

	for (i = 0; arr[i]; ++i) {
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}
	for (i = 0; arr[i]; ++i)
		arr[i] = output[i];
}

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp)
{
	int *output = new int[n];
	int i, count[10] = { 0 };	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void flashSort(int array[], int length)
{
	if (length == 0) return;
	int m = (int)((0.2 * length) + 2);
	int min, max, maxIndex;
	min = max = array[0];
	maxIndex = 0;
	for (int i = 1; i < length - 1; i += 2)
	{
		int small;
		int big;
		int bigIndex;

		if (array[i] < array[i + 1])
		{
			small = array[i];
			big = array[i + 1];
			bigIndex = i + 1;
		}
		else
		{
			big = array[i];
			bigIndex = i;
			small = array[i + 1];
		}
		if (big > max)
		{
			max = big;
			maxIndex = bigIndex;
		}
		if (small < min)
		{
			min = small;
		}
	}
	if (array[length - 1] < min)
	{
		min = array[length - 1];
	}
	else if (array[length - 1] > max)
	{
		max = array[length - 1];
		maxIndex = length - 1;
	}
	if (max == min)
	{
		return;
	}
	int* L = new int[m + 1];
	for (int t = 1; t <= m; t++)
	{
		L[t] = 0;
	}
	double c = (m - 1.0) / (max - min);
	int K;
	for (int h = 0; h < length; h++)
	{
		K = ((int)((array[h] - min) * c)) + 1;
		L[K] += 1;
	}
	for (K = 2; K <= m; K++)
	{
		L[K] = L[K] + L[K - 1];
	}
	int temp = array[maxIndex];
	array[maxIndex] = array[0];
	array[0] = temp;
	int j = 0;
	K = m;
	int numMoves = 0;
	while (numMoves < length)
	{
		while (j >= L[K])
		{
			j++;
			K = ((int)((array[j] - min) * c)) + 1;
		}
		int evicted = array[j];
		while (j < L[K])
		{
			K = ((int)((evicted - min) * c)) + 1;
			int location = L[K] - 1;
			int temp = array[location];
			array[location] = evicted;
			evicted = temp;
			L[K] -= 1;
			numMoves++;
		}
	}
	int threshold = (int)(1.25 * ((length / m) + 1));
	const int minElements = 30;
	for (K = m - 1; K >= 1; K--)
	{
		int classSize = L[K + 1] - L[K];
		if (classSize > threshold&& classSize > minElements)
		{
			flashSort(&array[L[K]], classSize);
		}
		else
		{
			if (classSize > 1)
			{
				InsertSort(&array[L[K]], classSize);
			}
		}
	}
	delete[] L;
}


int main()
{
	//Đặt bộ đếm thời gian tại thời điểm hiện tại
	clock_t start = clock();
	//Tạo biến số nguyên ngẫu nhiên
	srand(time(NULL));
	int n;
	string stage, size, algorithm, fileName;
	//Mở file resault.csv
	fstream resault;
	resault.open("resault.csv", ios::out);
	//Ghi dữ liệu mặc định lên file
	resault << "Input State,Input Size,selectionSort,insertionSort,binaryInsertionSort,bubbleSort,shakerSort,shellSort,heapSort,mergeSort,quickSort,countSort,radixSort,flashSort\n";
	for (int i = 1; i <= 4; i++) { //i tương ứng với tình trạng dữ liệu 1->4
		for (int j = 1; j <= 5; j++) { //j tương ướng với kích thước dữ liệu 1->5
			if (j == 1) {
				n = 1000;
				size = "1000";
			}
			else if (j == 2) {
				n = 3000;
				size = "3000";
			}
			else if (j == 3) {
				n = 10000;
				size = "10000";
			}
			else if (j == 4) {
				n = 30000;
				size = "30000";
			}
			else if (j == 5) {
				n = 100000;
				size = "100000";
			}
			if (i == 1) stage = "SORTED";
			else if (i == 2) stage = "REVERSED";
			else if (i == 3) stage = "RANDOM";
			else if (i == 4) stage = "NEARLYSORTED";

			resault << stage << "," << n << ","; //ghi tình trạng và kích thước dữ liệu lên file
			cout << stage << " " << n << " ";
			for (int k = 1; k <= 12; k++) { //k tương ứng với thuật toán 1->12
				int *arr = new int[n];
				if (i == 1) { //i = 1 tương tứng với tình trạng dữ liệu đã được sắp xếp
					for (int l = 0; l < n; l++) {
						arr[l] = l;
					}
				}
				else if (i == 2) { //i = 2 tương ứng với tình trạng dữ liệu được sắp xếp ngược
					for (int l = 0; l < n; l++) {
						arr[l] = n - l;
					}
				}
				else if (i == 3) { //i = 3 tương ứng với tình trạng dữ liệu RANDOM
					for (int l = 0; l < n; l++) {
						arr[l] = rand() % n;
					}
				}
				else if (i == 4) { //i = 4 tương ứng với tình trạng dữ liệu gần như đã được sắp xếp
					for (int l = 0; l < n; l++) {
						arr[l] = l;
					}
					arr[n / 2 - 1] = 1;
					arr[n / 2] = 2;
					arr[n / 3] = 3;
				}
				if (k == 1) {
					selectionSort(arr, n);
					algorithm = "selectionSort";
				}
				else if (k == 2) {
					InsertSort(arr, n);
					algorithm = "insertSort";
				}
				else if (k == 3) {
					binaryInsertionSort(arr, n);
					algorithm = "binaryInsertionSort";
				}
				else if (k == 4) {
					bubblesort(arr, n);
					algorithm = "bubbleSort";
				}
				else if (k == 5) {
					ShakerSort(arr, n);
					algorithm = "shakerSort";
				}
				else if (k == 6) {
					shellSort(arr, n);
					algorithm = "shellSort";
				}
				else if (k == 7) {
					heapSort(arr, n);
					algorithm = "heapSort";
				}
				else if (k == 8) {
					mergeSort(arr, 0, n - 1);
					algorithm = "mergeSort";
				}
				else if (k == 9) {
					quickSort(arr, 0, n - 1);
					algorithm = "quickSort";
				}
				else if (k == 10) {
					countSort(arr, n, 1);
					algorithm = "countSort";
				}
				else if (k == 11) {
					radixSort(arr, n);
					algorithm = "radixSort";
				}
				else if (k == 12) {
					flashSort(arr, n);
					algorithm = "flashSort";
				}
				resault << (double)(clock() - start) / CLOCKS_PER_SEC << ","; //Ghi thời gian thực hiện thuật toán
				cout << (double)(clock() - start) / CLOCKS_PER_SEC << " ";

				fileName = stage + "_" + size + "_" + algorithm + ".txt"; //Đặt tên file xuất ra kết quả từng lần chạy(240 file tương ứng với mỗi state_size_algorithm)
				ofstream fileXuatKqSapXep;
				fileXuatKqSapXep.open(fileName, ios::out); //Mở file để ghi kết quả sắp xếp
				for (int i = 0; i < n; i++) {
					fileXuatKqSapXep << arr[i] << " "; //Ghi kết quả sắp xếp
				}
				fileXuatKqSapXep.close(); //Đóng file ghi kết quả sắp xếp
				start = clock(); //Đặt lại bộ đếm thời gian
				delete[] arr; //Giải phóng bộ nhớ 
			}
			resault << "\n";
			cout << endl;
		}
	}
	resault.close(); //Đóng file resault.csv
	system("pause");
	return 0;
}