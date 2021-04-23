
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

const int ARRAYSIZE = 4;

void multiplyMatrices(int arrA[ARRAYSIZE], int arrB[ARRAYSIZE], int arrC[ARRAYSIZE])
{
	arrC[0] = (arrA[0] * arrB[0]) + (arrA[1] * arrB[2]);
	arrC[1] = (arrA[0] * arrB[1]) + (arrA[1] * arrB[3]);
	arrC[2] = (arrA[2] * arrB[0]) + (arrA[3] * arrB[2]);
	arrC[3] = (arrA[2] * arrB[1]) + (arrA[3] * arrB[3]);

	cout << arrC[0] << "\t" << arrC[1] << endl << arrC[2] << "\t" << arrC[3] << endl;
}

int main()
{
  // Declare variables
  int arrMatrixA[ARRAYSIZE] = { 2,0,4,2 };
  int arrMatrixB[ARRAYSIZE] = { 1,3,2,0 };
  int arrMatrixC[ARRAYSIZE] = { 1,0,1,0 };
  int arrResult[ARRAYSIZE];

  // Show application header
  cout << "Welcome to Multiplying Matrices!" << endl;
  cout << "--------------------------------" << endl << endl;
  
  cout << "#1" << endl;
  multiplyMatrices(arrMatrixA, arrMatrixB, arrResult);

  cout << "\n#2" << endl;
  multiplyMatrices(arrMatrixB, arrMatrixA, arrResult);

  cout << "\n#3" << endl;
  for (int i = 0; i < ARRAYSIZE; i++)
  {
	  arrResult[i] = arrMatrixA[i] * 2;
  }
  cout << arrResult[0] << "\t" << arrResult[1] << endl << arrResult[2] << "\t" << arrResult[3] << endl;


  cout << "\n#4" << endl;
  for (int i = 0; i < ARRAYSIZE; i++)
  {
	  arrResult[i] = arrMatrixB[i] * -4;
  }
  cout << arrResult[0] << "\t" << arrResult[1] << endl << arrResult[2] << "\t" << arrResult[3] << endl;

  // Show application close
  cout << "\nEnd of Multiplying Matrices" << endl;

}
