//==========================================================
//Linked List


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
	Node* next;
};

void printList(Node* n)
{
	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
}

int main()
{
	// Declare nodes
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	// Allocate 3 nodes
	head = new Node();
	second = new Node();
	third = new Node();

	// Assign Head node
	head->data = 5;
	head->next = second;

	// Assign second node
	second->data = 10;
	second->next = third;

	// Assign third node
	third->data = 15;
	third->next = NULL;

	// Print linked list
	printList(head);

}
