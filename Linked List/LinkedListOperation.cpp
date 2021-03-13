//==========================================================
//Linked List Insertion and Deletion


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

void deleteNode(int n)
{
	Node* temp3 = head;
	
	if (n == 1)
	{
		head = temp3->next;
		delete (temp3);
	}
	else
	{
		for (int i = 0; i < n - 2; i++) // n-1 node
		{
			temp3 = temp3->next;
		}

		Node* temp4 = temp3->next; // nth node
		temp3->next = temp4->next; // n+1 node

		delete temp4; // Delete nth node
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


int main()
{
	// Declare nodes
	head = NULL;
	insert(3, 1);
	insert(6, 2);
	insert(9, 1);
	insert(12, 2);
	insert(15, 5);

	// Declare variable
	int num;

	printList(head); // Print linked list
	
	cout << "\nWhich node would you like to delete: ";
	cin >> num;

	deleteNode(num); // Delete node

	printList(head); // Print linked list

}