//==========================================================
//
// Title:      Set Theory!
// Course:     CSC 1501
// Lab Number: 9
// Author:     Omar Faruk
// Date:       03/03/21
// Description:
//   Program to compute set theory using union, intersections,
// and magnitude.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

void Intersection(int arrA[], int arrB[],int arrC[])
{
	for (int i = 0; i < 10; i++)
	{
		if (arrA[i] == arrB[i]) // Intersection computation
		{
			arrC[i] = arrA[i];
		}
	}
}

void Union(int arrA[], int arrB[], int arrC[])
{
	for (int i = 0; i < 10; i++)
	{
		if (arrA[i] != arrB[i]) // Union computation
		{
			// Store answer values in array
			if (arrA[i] > 0)
			{
				arrC[i] = arrA[i];
			}
			else
			{
				arrC[i] = arrB[i];
			}
		}
	}
}

void Substraction(int arrA[], int arrB[], int arrC[])
{
	for (int i = 0; i < 10; i++)
	{
		if (arrA[i] && arrB[i] == false)
		{
			arrC[i] = arrA[i];
		}
	}
}

void printArray(int* arrA)
{
	for (int i = 0; i < 10; i++)
	{
		if (arrA[i] > 0)
		{
			cout << arrA[i] << " "; // Print array holding answers
		}
	
	}
}

void resetArray(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
}

int main()
{
	
	//Declare variables & Arrays
	int counter = 0;

	int arrA[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arrNotA[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int arrB[10] = { 0,2,0,4,0,6,0,8,0,10 };
	int arrC[10] = { 1,0,3,0,5,0,7,0,9,0 };
	int arrD[10] = { 1,2,3,0,5,0,7,0,0,0 };
	int arrAns[10], arrAns2[10], arrAns3[10];

	// Application header
	cout << "Welcome to Set Theory!" << endl;
	cout << "----------------------" << endl;

	//  A n D
	cout << "#1 A n D: ";
	Intersection(arrA, arrD, arrAns);
	printArray(arrAns);

	// ( B U C ) n A
	cout << "\n#2 ( B U C ) n A: ";
	Union(arrB, arrC, arrAns);
	Intersection(arrAns, arrA, arrAns2);
	printArray(arrAns2);

	// ( B U C ) n A
	cout << "\n#3 ( !C U C ) n A: ";
	Union(arrB, arrC, arrAns);
	Intersection(arrAns, arrA, arrAns2);
	printArray(arrAns2);
	resetArray(arrAns);
	resetArray(arrAns2);

	// A - D
	cout << "\n#4 A - D: ";
	Substraction(arrA, arrD, arrAns);
	printArray(arrAns);

	// N(!A U (C U D))
	cout << "\n#5 N(!A U (C U D)): ";
	Union(arrC, arrD, arrAns);
	Union(arrNotA, arrAns, arrAns2);
	for (int i = 0; i < 10; i++)
	{
		if (arrAns2[i] > 0)
		{
			counter++;
		}
	}
	cout << counter;
	resetArray(arrAns);
	resetArray(arrAns2);

	// D n C
	cout << "\n#6 D n C: ";
	Intersection(arrD, arrC, arrAns);
	printArray(arrAns);
	resetArray(arrAns);

	// N( B n C )
	cout << "\n#7 N( B n C ): ";
	Intersection(arrB, arrC, arrAns);
	counter = 0; // reset counter
	for (int i = 0; i < 10; i++)
	{
		if (arrAns[i] > 0)
		{
			counter++;
		}
	}
	cout << counter;
	resetArray(arrAns);
	
	// A U B U C U D
	cout << "\n#8 A U B U C U D: ";
	Union(arrA, arrB, arrAns);
	Union(arrC, arrD, arrAns2);
	Union(arrAns, arrAns2, arrAns3);
	printArray(arrAns3);

	// Application footer
	cout << "\nEnd of Set Theory";
}
