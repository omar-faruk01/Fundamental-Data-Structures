
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

class Node {

public:
	int data;
	Node* next;
	Node* prev;
};

// Global variable
Node* head = NULL;

// get a node
Node* getNewNode(int x) 
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void insertAtHead(int x)
{
	Node* newNode = getNewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void printNodes()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void reversePrint()
{
	Node* temp = head;

	if (temp == NULL) // Return to main if list is empty
	{
		return;
	}
	while (temp->next != NULL) // Traverse to last node
	{
		temp = temp->next;
	}

	while (temp != NULL) // Print nodes in reverse
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
}

int main()
{

	//Initialize head ptr
	head = NULL;

	//Create nodes
	insertAtHead(2);
	insertAtHead(4);
	insertAtHead(6);

	// Print nodes
	cout << "Printing nodes: ";
	printNodes();
	cout << "\nReverse printing nodes: ";
	reversePrint();
}