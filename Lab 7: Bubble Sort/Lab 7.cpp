//==========================================================
//
// Title:      Bubble Sorter
// Course:     CSC 1501
// Lab Number: 7
// Author:     Omar Faruk
// Date:       02/18/21
// Description:
//   Creating a sorting algorithim to bubble sort a list and
// count all the operations.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// Globals
const int ARRAYSIZE = 10;

void swap(int* x, int* y)
{
	int temp;
	
	// Swap two elements
	temp = *x;
	*x = *y;
	*y = temp;
}

int bubbleSorter(int arr[], int size)
{
	int counter = 0;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				counter= counter + 2;
			}
			counter = counter + 1;
		}
	}

	return counter;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	// Declare variable
	int operations;

	// Declare array
	int arrList1[ARRAYSIZE] = { 1,3,7,5,2,4,6,8,9,10 };
	int arrList2[ARRAYSIZE] = { 10,9,8,7,6,5,4,3,2,1 };
	int arrList3[ARRAYSIZE] = { 1,10,2,9,3,8,4,7,5,6 };

	// Application header
	cout << "Welcome to Bubble Sorter!" << endl;
	cout << "-------------------------" << endl << endl;

	// Array list 1
	cout << "Initial list: ";
	printArray(arrList1, ARRAYSIZE);
	operations = bubbleSorter(arrList1, ARRAYSIZE);
	cout << "\nSorted  list: ";
	printArray(arrList1, ARRAYSIZE);
	cout << "\nOperations: " << operations << endl << endl;

	// Array list 1
	cout << "Initial list: ";
	printArray(arrList2, ARRAYSIZE);
	operations = bubbleSorter(arrList2, ARRAYSIZE);
	cout << "\nSorted  list: ";
	printArray(arrList2, ARRAYSIZE);
	cout << "\nOperations: " << operations << endl << endl;

	// Array list 3
	cout << "Initial list: ";
	printArray(arrList3, ARRAYSIZE);
	operations = bubbleSorter(arrList3, ARRAYSIZE);
	cout << "\nSorted  list: ";
	printArray(arrList3, ARRAYSIZE);
	cout << "\nOperations: " << operations << endl << endl;

	// Application footer
	cout << "End of Bubble Sorter!" << endl;
}
