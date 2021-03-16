//==========================================================
//
// Title:      Truth Tables
// Course:     CSC 1501
// Lab Number: Lab 2
// Author:     Omar Faruk
// Date:       01/12/2021
// Description:
//   Creating an application to provide solutions for five logical
// statements for 8 possible combinations of A,B,& C by using logical
// operators, branching, arrays, and loops.
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
  // Declare constants
  const int ARRAY_SIZE = 8;

  // Declare Arrays
  int arrayA[ARRAY_SIZE] = {0, 0, 0, 0, 1, 1, 1, 1};
  int arrayB[ARRAY_SIZE] = {0, 0, 1, 1, 0, 0, 1, 1};
  int arrayC[ARRAY_SIZE] = {0, 1, 0, 1, 0, 1, 0, 1};

  // Show application header
  cout << "Welcome to Logical Statements!" << endl;
  cout << "------------------------------" << endl << endl;

  cout << "Below are solutions to five logical statements: " << endl << endl;

  // Print first logical staement
  cout << "[1] (A and B) or (A and C)" << endl;
  // Loop to iterate over arrays 
  for (int i = 0; i < 8; i++)
  {
	  // statement if true,1 or false,0
	  if ((arrayA[i] && arrayB[i] == true) || (arrayA[i] && arrayC[i] == true))
	  {
		  cout << "(A and B) or (A and C) is  true when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
	  else
	  {
		  cout << "(A and B) or (A and C) is false when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
  }

  // Print second logical statement
  cout << endl << "[2] (A and C) and (B and !C)" << endl;
  // Loop to iterate over arrays
  for (int i = 0; i < 8; i++)
  {
	  // statement if true,1 or false,0
	  if ((arrayA[i] && arrayC[i] == true) && (arrayB[i] && !arrayC[i] == true))
	  {
		  cout << "(A and C) and (B and !C) is  true when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
	  else
	  {
		  cout << "(A and C) and (B and !C) is false when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
  }

  // Print third logical statement
  cout << endl << "[3] (A or B) and !(B or C)" << endl;
  // Loop to iterate over arrays
  for (int i = 0; i < 8; i++)
  {
	  // statement if true,1 or false,0
	  if ((arrayA[i] || arrayB[i] == true) && !(arrayB[i] || arrayC[i] == true))
	  {
		  cout << "(A or B) and !(B or C) is  true when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
	  else
	  {
		  cout << "(A or B) and !(B or C) is false when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
  }

  // Print fourth logical statement
  cout << endl << "[4] (A or (B and C)) and (!A and !B)" << endl;
  // Loop to iterate over arrays
  for (int i = 0; i < 8; i++)
  {
	  // statement if true,1 or false,0
	  if (((arrayA[i] || (arrayB[i] && arrayC[i]))== true) && (!arrayA[i] && !arrayB[i] == true))
	  {
		  cout << "(A or (B and C)) and (!A and !B) is  true when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
	  else
	  {
		  cout << "(A or (B and C)) and (!A and !B) is false when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
  }

  // Print fifth logical statement
  cout << endl << "[5] ((B and C) or (C and A)) and (!(A or B) and C)" << endl;
  // Loop to iterate over arrays
  for (int i = 0; i < 8; i++)
  {
	  // statement if true,1 or false,0
	  if ((((arrayB[i] && arrayC[i]) || (arrayC[i] && arrayA[i])) && (!(arrayA[i] || arrayB[i]) && arrayC[i])))

	  {
		  cout << "(A or (B and C)) and (!A and !B) is  true when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
	  else
	  {
		  cout << "(A or (B and C)) and (!A and !B) is false when A = " << arrayA[i] << ", B =" << arrayB[i] << ", and C =" << arrayC[i] << endl;
	  }
  }

  // Show application close
  cout << "\nEnd of Logical Statements!" << endl;

}
