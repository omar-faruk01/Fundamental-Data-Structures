#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream> 
#include <string>
#include <list>
using namespace std;

struct stack
{
	int size;
	int top;
	int* s;
};

int isEmpty(stack list)
{
	if (list.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull(stack list)
{
	if (list.top == list.size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(stack *list, int x)
{
	if (list->top == list->size-1)
	{
		cout << "Stack overflow";
	}
	else
	{
		list->top++;
		list->s[list->top] = x;
	}
}

int peak(stack list, int pos)
{
	int x = -1;
	if (list.top-pos+1<0)
	{
		cout << "Invalid position";
	}
	else
	{
		x = list.s[list.top - pos + 1];
	}
	return x;
}

int stackTop(stack list)
{
	if (list.top == -1)
	{
		return -1;
	}
	else
	{
		return list.s[list.top];
	}
}

int pop(stack* list)
{
	int x = -1;
	if (list->top ==-1)
	{
		cout << "Stack underflow";
	}
	else
	{
		x = list->s[list->top];
		list->top--;
	}

	return x;
}
int main()
{
	// declare vars
	int x;
	struct stack st;
	st.size = 5;
	st.s = new int[st.size];
	st.top = -1;

	// stack adt
	push(&st, 10);
	push(&st, 15);
	push(&st, 20);
	push(&st, 25);
	push(&st, 35);

	x = peak(st, 2);
	cout << "Peak at pos 2: " x << endl;

	x = pop(&st);
	cout <<"Pop: "<< x << endl;
	
	x = isEmpty(st);
	cout <<"Is stack empty? "<< x << endl;

	x = isFull(st);
	cout << "Is stack full? " << x << endl;

	x = stackTop(st);
	cout <<"Top value: "<< x << endl;
	

}