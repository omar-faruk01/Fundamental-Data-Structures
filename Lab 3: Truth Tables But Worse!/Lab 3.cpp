//==========================================================
//
// Title:      Truth Tables But Worse!
// Course:     CSC 1501
// Lab Number: 3
// Author:     Omar Faruk
// Date:       01/25/2021
// Description:
//   Creating a program to solve 4 logical statements with 
// operators using functions and arrays.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// Declare constants
const int ARRAY_SIZE = 8;

int nor(int arrA[ARRAY_SIZE], int arrB[ARRAY_SIZE], int arrC[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (!(arrA[i] || arrB[i]) == true)
		{
			arrC[i] = 1;
		}
		else
		{
			arrC[i] = 0;
		}
	}

	return arrC[ARRAY_SIZE];
};

int exor(int arrA[ARRAY_SIZE], int arrB[ARRAY_SIZE], int arrC[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (!(arrA[i] ^ !arrB[i]) == true)
		{
			arrC[i] = 1;
		}
		else
		{
			arrC[i] = 0;
		}
	}

	return arrC[ARRAY_SIZE];
};

int implies(int arrA[ARRAY_SIZE], int arrB[ARRAY_SIZE], int arrC[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if ((!arrA[i] || arrB[i]) == true)
		{
			arrC[i] = 1;
		}
		else
		{
			arrC[i] = 0;
		}
	}

	return arrC[ARRAY_SIZE];
};

int nand(int arrA[ARRAY_SIZE], int arrB[ARRAY_SIZE], int arrC[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (!(arrA[i] && arrB[i]) == true)
		{
			arrC[i] = 1;
		}
		else
		{
			arrC[i] = 0;
		}
	}

	return arrC[ARRAY_SIZE];
};
int exnor(int arrA[ARRAY_SIZE], int arrB[ARRAY_SIZE], int arrC[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (!(!(arrA[i] ^ !arrB[i])) == true)
		{
			arrC[i] = 1;
		}
		else
		{
			arrC[i] = 0;
		}
	}

	return arrC[ARRAY_SIZE];
};

void printArray(int arrA[ARRAY_SIZE], int arrB[ARRAY_SIZE], int arrC[ARRAY_SIZE], int arrD[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (arrD[i] == 1)
		{
			cout << "True  when A = " << arrA[i] << ", B =" << arrB[i] << ", and C =" << arrC[i] << endl;
		}
		else
		{
			cout << "False when A = " << arrA[i] << ", B =" << arrB[i] << ", and C =" << arrC[i] << endl;
		}
	}
};

int main()
{
	// Declare arrays of variables
	int arrayA[ARRAY_SIZE] = { 0, 0, 0, 0, 1, 1, 1, 1 };
	int arrayB[ARRAY_SIZE] = { 0, 0, 1, 1, 0, 0, 1, 1 };
	int arrayC[ARRAY_SIZE] = { 0, 1, 0, 1, 0, 1, 0, 1 };
	int arrayNotC[ARRAY_SIZE];
	
	// Fill !C array
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arrayNotC[i] = !arrayC[i];
	}

	// Declare arrays of operator functions to store results 
	int arrayNor[ARRAY_SIZE], arrayExor[ARRAY_SIZE], arrayNand[ARRAY_SIZE];
	int arrayImplies[ARRAY_SIZE], arrayExnor[ARRAY_SIZE], arrayImpliesV2[ARRAY_SIZE];
	
	// Application header
	cout << "Welcome to Truth Tables But Worse!" << endl
		<< "-----------------------------------" << endl;

	// Problem 1
	cout << "\n1. (A nor C) xor B" << endl;
	nor(arrayA, arrayC, arrayNor); // A nor C function 
	exor(arrayNor, arrayB, arrayExor); // exlcusive or  B function
	printArray(arrayA, arrayB, arrayC, arrayExor); // function to print array

	// Problem 2
	cout << "\n2. (B implies C) nand (A nor B)" << endl;
	implies(arrayB, arrayC, arrayImplies); // B Implies C function
	nor(arrayA, arrayB, arrayNor); // A Nor B function
	nand(arrayImplies, arrayNor, arrayNand); // Nand function
	printArray(arrayA, arrayB, arrayC, arrayNand); // function to print array

	// Problem 3
	cout << "\n3. (A xor B) implies (B xnor C)" << endl;
	exor(arrayA, arrayB, arrayExor); // A xor B function
	exnor(arrayB, arrayC, arrayExnor); // B xnor C function
	implies(arrayExor, arrayExnor, arrayImplies); // Implies function
	printArray(arrayA, arrayB, arrayC, arrayImplies); // function to print array
	
	// Problem 4
	cout << "\n4. (A implies B) implies !C" << endl;
	implies(arrayA, arrayB, arrayImplies); // A Implies B function
	implies(arrayImplies, arrayNotC, arrayImpliesV2); // Implies !C function
	printArray(arrayA, arrayB, arrayC, arrayImpliesV2); // function to print array

	// Application footer
	cout << "\nEnd of Truth Tables But Worse!";

}
