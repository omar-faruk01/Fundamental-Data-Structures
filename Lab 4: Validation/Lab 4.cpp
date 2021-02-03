//==========================================================
//
// Title:      The Validator
// Course:     CSC 1501
// Lab Number: 4
// Author:     Omar Faruk
// Date:       01/28/21
// Description:
//	Creating a program to check if the logical statements
// are valid or invalid and computing implies logical statements
// using functions and arrays.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// Declare Globals
const int ARRAY_SIZE = 16;

void implies(int arrA[ARRAY_SIZE], int arrB[ARRAY_SIZE], int arrC[ARRAY_SIZE])
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
};

int main()
{
	// Declare constants
	const int COLMFIT1 = 10;
	const int COLMFIT2 = 1;

	// Declare Variables 
	int valid;

	// Declare arrays of variables
	int arrayRocket[ARRAY_SIZE] = { 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 };
	int arrayAstronaut[ARRAY_SIZE] = { 0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1 };
	int arrayTrained[ARRAY_SIZE] = { 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1 };
	int arrayEducated[ARRAY_SIZE] = { 0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 }; 

	// Store results of logical statements in arrays
	int arrayProp1[ARRAY_SIZE], arrayProp2[ARRAY_SIZE], arrayProp3[ARRAY_SIZE];
	int arrayConclusion[ARRAY_SIZE];
	string arrayValidation[ARRAY_SIZE];

	// Compute Propisitions:
	implies(arrayRocket, arrayAstronaut, arrayProp1); // Rocket implies astronaut
	implies(arrayAstronaut, arrayTrained, arrayProp2); // Astronaut implies trained
	implies(arrayTrained, arrayEducated, arrayProp3); // Trained implies educated

	// Compute Conclusion: 
	implies(arrayEducated, arrayRocket, arrayConclusion);// Educated implies rocket

	// Application header
	cout << "Welcome to The Validator!" << endl;
	cout << "-------------------------" << endl;

	// Print output of arrays for all logical statements
	cout << setw(COLMFIT1) << left << "Rocket" << setw(COLMFIT1) << left << "Astronaut"
		<< setw(COLMFIT1) << left << "Trained" << setw(COLMFIT1) << left << "Educated  |" 
		<< setw(COLMFIT1) << left << " R -> A" << setw(COLMFIT1) << left << "A -> T" 
		<< setw(COLMFIT1) << left << "T -> E" << setw(COLMFIT1) << left << "E -> R"<< endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << setw(COLMFIT1) << left << arrayRocket[i] << setw(COLMFIT1) << left << arrayAstronaut[i]
			<< setw(COLMFIT1) << left << arrayTrained[i] << setw(COLMFIT1) << left << arrayEducated[i]
			<< setw(COLMFIT2) << left << "| "
			<< setw(COLMFIT1) << left << arrayProp1[i] << setw(COLMFIT1) << left << arrayProp2[i]
			<< setw(COLMFIT1) << left << arrayProp3[i] << setw(COLMFIT1) << left << arrayConclusion[i]
			<< setw(COLMFIT1)<< left;

		// Print all invalid occurances
		if (((arrayProp1[i] && arrayProp2[i] && arrayProp3[i]) == 1) & (arrayConclusion[i] == 0))
		{
			cout << setw(COLMFIT1) << left << "Invalid";
			valid = 0; // Used to determine and initialize if logical statement is invalid 
		}
			cout << endl;
	}
	
	//Print if logical statement is valid or invalid
	if (valid == 0)
	{
		cout << "\nThe logical statement is invalid!" << endl;
	}
	else
	{
		cout << "\nThe logical statement is valid!" << endl;
	}

	// Application footer
	cout << "\nEnd of The Validator" << endl;
};

