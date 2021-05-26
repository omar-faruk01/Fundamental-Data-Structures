#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

class Node
{
public:
	int data;
	Node* link;
};

// Global
Node* top = NULL;

void Push(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->link = top;
	top = temp;
}

void Pop()
{
	Node* temp;
	if (top == NULL)
	{
		return;
	}
	temp = top;
	top = top->link;
	delete(temp);
}

void Top()
{
	 Node current;
	 current = *top;
	 cout << current.data;
}

int main()
{
	Push(2);
	Push(5);
	Pop();

	Top();

	
}