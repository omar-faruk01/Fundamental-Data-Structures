//==========================================================
//
// Title:      Decimal 2 Base Conversion
// Course:     CSC 1501
// Lab Number: 5
// Author:     Omar Faruk
// Date:       02/03/21
// Description:
//   Creating an application to convert a decimal number to
// the user inputted base nnumber using functions and arrays
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// Globals
const int ARRAY_SIZE = 8;

void decimalConversion(int b, int d, int arrA[ARRAY_SIZE])
{
	int r;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		r = d % b; // Compute remainder
		d = d / b; // Compute decimal number
		arrA[i] = r; // Store remainder in array
	}
}
void printArray(int arrA[ARRAY_SIZE])
{
	for (int i = ARRAY_SIZE-1; i>=0; i--) // Print array in reverse order
	{
		cout << arrA[i];
	}
}
int main()
{
	int b, d; // Declare variables
	int arrResults[ARRAY_SIZE]; // Declare array

	
	cout << "Welcome to Decimal 2 Base Conversion!" << endl; // Application header
	cout << "-------------------------------------" << endl << endl;

	// Get user input
	cout << "Decimal: ";
	cin >> d;
	cout << "Base: ";
	cin >> b;
	decimalConversion(b, d, arrResults); // Compute decimal to binary conversion
	cout << "Result: ";
	printArray(arrResults); // Print the results of conversion

	cout << "\n\nEnd of Decimal 2 Base Conversion!" << endl; // Application footer
}