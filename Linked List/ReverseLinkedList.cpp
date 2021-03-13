//==========================================================
// Reverse Linked List

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

// Declare globals
Node* head = NULL;

void insert(int data, int n)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;

	if (n == 1)
	{
		temp1->next = head;
		head = temp1;
	}
	else
	{
		Node* temp2 = head;
		for (int i = 0; i < n - 2; i++) // n-1 node
		{
			temp2 = temp2->next;
		}
		temp1->next = temp2->next; // n+1 node
		temp2->next = temp1; // nth node 
	}
}

void printList(Node* n)
{
	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
}

Node* reverse(Node* head)
{
	Node* temp, * prev, *current,*next;
	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

int main()
{
	// Declare nodes
	head = NULL;
	insert(3, 1);
	insert(6, 2);
	insert(9, 1);
	insert(12, 2);
	insert(15, 5);

	printList(head); // Print linked list

	cout << endl;

	head = reverse(head); // Reverse linked list
	printList(head); // Print reversed linked list
}