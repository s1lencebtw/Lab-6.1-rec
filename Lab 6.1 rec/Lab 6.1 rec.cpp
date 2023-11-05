#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void printArray(int* arr, int size, int i);
void generateArray(int* arr, int size, int min, int max, int i);
int countElements(int* arr, int size, int index, int count);
int sumElements(int* arr, int size, int index, int sum);
void replaceElements(int* arr, int size, int index);

int main() {
	const int arrSize = 25;
	int t[arrSize];

	generateArray(t, arrSize, 5, 90, 0);

	cout << "Original array: ";
	printArray(t, arrSize, 0);


	cout << "Number of elemnts: " << countElements(t, arrSize, 0, 0) << endl;

	cout << "Sum of elements: " << sumElements(t, arrSize, 0, 0) << endl;

	replaceElements(t, arrSize, 0);

	cout << "Modified:       ";
	printArray(t, arrSize, 0);

	return 0;
}

void generateArray(int* arr, int size, int min, int max, int i) {
	if (i < size) {
		arr[i] = min + rand() % (max - min + 1);
		generateArray(arr, size, min, max, i + 1);
	}
}

void printArray(int* array, int size, int i) {
	cout << setw(4) << array[i] << " ";
	if (i < size - 1)
		printArray(array, size, i + 1);
	else cout << endl;
}


int sumElements(int* arr, int size, int index, int sum) {
	if (index < size) {
		if (arr[index] % 2 == 0 || (index % 8 != 0))
		{
			sum += arr[index];
		}
		sumElements(arr, size, index + 1, sum);
	}
	else return sum;
}

int countElements(int* arr, int size, int index, int count) {
	if (index < size) {
		if (arr[index] % 2 == 0 || (index % 8 != 0)) {
			count++;
		}
		countElements(arr, size, index + 1, count);
	}
	else return count;
}

void replaceElements(int* arr, int size, int index) {
	if (index < size) {
		if (arr[index] % 2 == 0 || (index % 8 != 0)) {
			arr[index] = 0;
		}
		replaceElements(arr, size, index + 1);
	}
	else return;
}