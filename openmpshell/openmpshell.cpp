#include "pch.h"

#include <iostream>
#include "malloc.h"
#include "omp.h"
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#define MAX_SIZE 1000
using namespace std;
/*

//a[] is sort , n is size

void print(int a[], int size)
{

	for (int i = 0; i < size; i++)
		cout << a[i] << "";
	cout << endl;
}







void ShellSort(int a[], int n)
{
	int gap;
	int j;
	int i;
	int element;

	for (gap = n / 2; gap > 0; gap /= 2)
	{
#pragma omp parallel for shared( a, gap,n) private(i,j,element) default(none)
		for (i = gap; i < n; i++)
		{
#pragma omp parallel
			element = a[i];
			for (j = i; j >= gap; j -= gap)
			{
#pragma omp critical
				if (element < a[j - gap])
					a[j] = a[j - gap];

			}

			a[j] = element;

		}
	}
}



void merge(int a[], int n, int t[]) {
	int i = 0;
	int j = n / 2;
	int ti = 0;

	while (i < n / 2 && j < n) {
		if (a[i] < a[j]) {
			t[ti] = a[i];
			ti++; i++;
		}
		else {
			t[ti] = a[j];
			ti++; j++;
		}
	}
	while (i < n / 2)
	{
		t[ti] = a[i];
		ti++; i++;
	}
	while (j < n)
	{

		t[ti] = a[j];
		ti++; j++;
	}
	memcpy(a, t, n * sizeof(int));

}



void mergeSort(int a[], int t[], int n)
{

	if (n > 1) {

		for (int i = 0; i < n / 2; i++) {
			t[i] = a[i];
		}

		mergeSort(a, t, n / 2);

		for (int i = n / 2; i < n; i++) {
			t[i] = a[i];
		}

		mergeSort(a, t, n / 2);



		ShellSort(a, n);
		//merge(a, 0, n + t);

	}
}


int main()

{
	int threads = 2;

	int  t[MAX_SIZE];
	int n = 2000;
	int a[2000];
	int i;
	srand((time(NULL)));

#pragma omp parallel for num_threads(i)
	for (i = 0; i < n; i++)
	{
		a[i] = (rand() % 100000) + 1;

	}

	double startTime = clock();

	cout << "enter element:" << endl;
	cin >> n;
	/*
	cout << "enter elements the one that you put earlier:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	cout << "array seq before sorting: ";

	print(a, n);
	ShellSort(a, n);


	cout << "array seq after sorting: ";
	print(a, n);
	*/

	/*
	cout << "enter the size of the array" << endl;
	cin >> n;

	cout << "please enter the elements of the array" << endl;
	for (int i = 0; i < n; i++) {
		cout << "enter the element of shell:" << i << endl;
		cin >> a[i];
	}
	print(a, n);
	ShellSort(a, n);
	mergeSort(a, 0, n - 1);

	cout << "\tSorted Array Elements with shell" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}


	ShellSort(a, n);
	double endTime = clock();
	int totalTime = endTime - startTime; 

	cout << "This is the time it took to run.\n" << endl;
	cout << totalTime / threads << n << endl;


}
*/

// the right one shellopenmp
void printarray(int *array, int length) //print array elements
{
	int i = 0;
	for (i = 0; i < length; i++)
		printf("%d\n", array[i]);
}



void shellsort(int numbers[], int array_size)
{
	{
		int gap;
		int j;
		int i;
		int element;

		for (gap = array_size / 2; gap > 0; gap /= 2)
		{
#pragma omp parallel for shared( numbers, gap,array_size) private(i,j,element) default(none)
			for (i = gap; i < array_size; i++)
			{
#pragma omp parallel
				element = numbers[i];
				for (j = i; j >= gap; j -= gap)
				{
#pragma omp critical
					if (element < numbers[j - gap])
						numbers[j] = numbers[j - gap];

				}

				numbers[j] = element;

			}
		}
	}

}

void merge(int a[], int array_size, int t[]) {
	int i = 0;
	int j = array_size / 2;
	int ti = 0;

	while (i < array_size / 2 && j < array_size) {
		if (a[i] < a[j]) {
			t[ti] = a[i];
			ti++; i++;
		}
		else {
			t[ti] = a[j];
			ti++; j++;
		}
	}
	while (i < array_size / 2)
	{
		t[ti] = a[i];
		ti++; i++;
	}
	while (j < array_size)
	{

		t[ti] = a[j];
		ti++; j++;
	}
	memcpy(a, t, array_size * sizeof(int));

}
void mergeSort(int *numbers, int t[], int array_size)
{

	if (numbers > 0) {

		for (int i = 0; i < array_size / 2; i++) {
			t[i] = numbers[i];
		}

		mergeSort(numbers, t, array_size / 2);

		for (int i = array_size / 2; i < array_size; i++) {
			t[i] = numbers[i];
		}



		merge(numbers, array_size + 1, 0);
	}

};



int main(){
	int threads = 2;

	int  t[MAX_SIZE];
	int array_size = 2000;
	int numbers[2000];
	int i;
	srand((time(NULL)));

#pragma omp parallel for num_threads(i)
	for (i = 0; i < array_size; i++)
	{
		numbers[i] = (rand() % 100000) + 1;

	}

	double startTime = clock();

	cout << "enter element:" << endl;
	cin >> array_size;
	
	cout << "enter elements the one that you put earlier:" << endl;
	for (int i = 0; i < array_size; i++)
	{
		cin >> numbers[i];

	}
	cout << "array seq before sorting: ";

	printarray(numbers, array_size);

	shellsort(numbers, array_size);

	cout << "array seq after sorting: ";

	printarray(numbers, array_size);




	//cout << "\tSorted Array Elements with shell" << endl;
	//for (int i = 0; i < array_size; i++) {
	//	cout << numbers[i] << "\t";
	//}

	//shellsort(numbers, array_size);


	if (array_size < 100) {
		std::cout << "Sorted array:\t ";
		printarray(numbers, array_size);
	}


	shellsort(numbers, array_size);
	

	double endTime = clock();
	int totalTime = endTime - startTime;
	
	cout << "This is the time it took to run.\n" << endl;
	cout << totalTime / threads << array_size << endl;


}



