
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// Globals
const int ARRAY_SIZE = 8;
const int ARRAY_SIZE2 = 7;

void hammingTransmitter(bool arrA[ARRAY_SIZE], bool arrB[ARRAY_SIZE2])
{
	bool a, b, c; // Declare variables

	//Compute security
	a = ((arrA[4] + arrA[5] + arrA[7]) % 2);
	b = ((arrA[4] + arrA[6] + arrA[7]) % 2);
	c = ((arrA[5] + arrA[6] + arrA[7]) % 2);

	cout << "Binary: ";
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << arrA[i] << " ";
	}

	// store hamming transmitter array
	arrB[0] = a;
	arrB[1] = b;
	arrB[2] = arrA[4];
	arrB[3] = c;
	arrB[4] = arrA[5];
	arrB[5] = arrA[6];
	arrB[6] = arrA[7];
	
	//output hamming transmitter
	cout << "\nResults: ";
	for (int i = 0; i < ARRAY_SIZE2; i++)
	{
		cout << arrB[i]<< " ";
	}
}

void decimalConversion( int d, bool arrA[ARRAY_SIZE])
{
	int r, b = 2;
	for (int i = ARRAY_SIZE - 1; i >= 0; i--)
	{
		r = d % b; // Compute remainder
		d = d / b; // Compute decimal number
		arrA[i] = r; // Store remainder in array
	}
}



int main()
{
	int d; // Declare variables
	bool arrResults[ARRAY_SIZE], arrTrans[ARRAY_SIZE2]; // Declare array

	cout << "Welcome to Hamming Transmitter!" << endl; // Application header
	cout << "-------------------------------" << endl;

	// Get user input
	for (int i = 0; i < 5; i++)
	{
		cout << "\nDecimal: ";
		cin >> d;
		decimalConversion(d, arrResults); // Compute decimal to binary conversion
		hammingTransmitter(arrResults, arrTrans);
		cout << endl;
	}

	cout << "\nEnd of Hamming Transmitter" << endl; // Application footer
}
