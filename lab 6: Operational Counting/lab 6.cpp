//==========================================================
//
// Title:      Operational Counting
// Course:     CSC 1501
// Lab Number: 6
// Author:     Omar Faruk
// Date:       02/11/2021
// Description:
//  Creating a program that provides n + (n+1) up to the
// user input and another math computation to also add all 
// numbers leading to user input to determine which method
// has less operations.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main()
{
	// Declare variables
	int userInput;
	int sum = 0, sum2 = 0, counter = 0, counter2 = 0;
	
	// Take user input
	cout << "Enter an integer: ";
	cin >> userInput;

	// For loop method
	for (int i = 1; i < userInput+1; i++)
	{
		sum = sum + i;
		counter++;
	}

	// Print for loo[ method
	cout << "\nFirst Method" << endl
	 << "Sum: " << sum << endl
	 << "Operations: " << counter-1 << endl;


	// Computing method
	sum2 = (userInput * (userInput + 1)) / 2;
	counter2 = 3; // * + / is only 3 operations

	// Print computing method
	cout << "\nSecond Method" << endl
	<< "Sum: " << sum2 << endl
	 << "Operations: " << counter2 << endl;
}
