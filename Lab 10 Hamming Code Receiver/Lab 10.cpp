//==========================================================
//
// Title:      Hamming Code Receiver
// Course:     CSC 1501
// Lab Number: 10
// Author:     Omar Faruk
// Date:       03/10/21
// Description:
//   Creating a hamming code transmitter application that outputs
// correct message, location of error, and decimal.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

void hammingCode(int arr[], int arrAns[])
{
	int a, b, c, d;

	a = (arr[0] + arr[2] + arr[4] + arr[6]) % 2;
	b = (arr[1] + arr[2] + arr[5] + arr[6]) % 2;
	c = (arr[3] + arr[4] + arr[5] + arr[6]) % 2;

	d = (a* 1) + (b*2) + (c*4); // find error location

	// Fill all indexes of array
	for (int i = 0; i < d-1; i++)
	{
		arrAns[i] = arr[i];
	}
	if (arr[d-1] == 1)
	{
		arrAns[d-1] = 0;
	}
	else
	{
		arrAns[d-1] = 1;
	}
	arrAns[8] = d;
	for (int i = d; i < 7; i++)
	{
		arrAns[i] = arr[i];
	}
	arrAns[8] = d;
	
}

void printCode(int arr[])
{
	cout << "Correct hamming code: ";
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i];
	}

	cout << "\nCorrect message code: "
		<< arr[2] << " " << arr[4] << " " << arr[5] << " " << arr[6] << endl;

	// convert binary to decimal
	int value = arr[2] * 8 + arr[4] * 4 + arr[5] * 2 + arr[6] * 1;
	cout << "Decimal value: " << value << endl;

	// error location print
	cout << "Error location: "<<arr[8] << endl;
}
void resetArray(int arr[])
{
	for (int i = 0; i < 8; i++)
	{
		arr[i] = 0;
	}
}

int main()
{

  // Declare variables and arrays
  int arrAns[8];
  int arr1[7] = {1,1,0,1,0,1,0};
  int arr2[7] = {0,0,1,0,1,1,1};
  int arr3[7] = {1,0,1,0,1,0,1};
  int arr4[7] = {1,0,0,1,0,0,1};
  int arr5[7] = {0,1,1,0,0,1,1};

  

  // Show application header
  cout << "Welcome to Hamming Code Transmitter!" << endl;
  cout << "------------------------------------" << endl << endl;

  //Problem 1
  cout << "Problem 1: ";
  for (int i = 0; i < 7; i++)
  {
	  cout << arr1[i];
  }
  cout << endl;
  resetArray(arrAns);
  hammingCode(arr1,arrAns);
  printCode(arrAns);
  resetArray(arrAns);

  cout << "\nProblem 2: ";
  for (int i = 0; i < 7; i++)
  {
	  cout << arr2[i];
  }
  cout << endl;
  hammingCode(arr2, arrAns);
  printCode(arrAns);
  resetArray(arrAns);
  
  cout << "\nProblem 3: ";
  for (int i = 0; i < 7; i++)
  {
	  cout << arr3[i];
  }
  cout << endl;
  hammingCode(arr3, arrAns);
  printCode(arrAns);
  resetArray(arrAns);

  cout << "\nProblem 4: ";
  for (int i = 0; i < 7; i++)
  {
	  cout << arr4[i];
  }
  cout << endl;
  hammingCode(arr4, arrAns);
  printCode(arrAns);
  resetArray(arrAns);

  cout << "\nProblem 5: ";
  for (int i = 0; i < 7; i++)
  {
	  cout << arr5[i];
  }
  cout << endl;
  hammingCode(arr5, arrAns);
  printCode(arrAns);
  resetArray(arrAns);

  // Show application close
  cout << "\nEnd of Hamming Code Transmitter" << endl;
  
}
