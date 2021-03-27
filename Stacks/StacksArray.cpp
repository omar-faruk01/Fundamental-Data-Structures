#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

//Globals
const int ARRAYSIZE = 101;
int A[ARRAYSIZE];
int top = -1;

void Push(int x)
{
	if (top == ARRAYSIZE-1)
	{
		cout << "Error: Stack Overflow\n";
		return;
	}

	// pre increment to enter data into next array index
	A[++top] = x;
}

void Pop()
{
	if (top == -1)
	{
		cout << "Error: Stack is empty\n";
		return;
	}
	top = top - 1;
}

int Top()
{
	return A[top];
}

int main()
{
	Push(2);
	Push(5);
	Push(10);
	Pop();
	Push(12);

	for (int i = 0; i <= top; i++) // Print stack
	{
		cout << A[i] << " ";
	}
}