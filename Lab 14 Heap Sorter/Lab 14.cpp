#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <vector> // For vector data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

//Global
const int ARRAYSIZE = 8;

void insertHeap(int arr[], int n)
{
    int temp, i = n;
    temp = arr[n];

    while (i > 1 && temp > arr[i / 2]) // check if parent node is smaller than inserted number
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }

    arr[i] = temp;
}
int deleteHeap(int arr[], int n)
{
    int i, j, x, temp, val;
    val = arr[1];
    x = arr[n]; // store last element as x
    arr[1] = arr[n]; // store last element in 1st element of heap array
    arr[n] = val; // store deleted number in the last element of array
    i = 1; j = i * 2; // j points at left child of i

    while (j < n - 1)
    {
        if (arr[j + 1] > arr[j]) // which child is larger
        {
            j = j + 1; // store j as larger child
        }
        if (arr[i] < arr[j])
        {
            temp = arr[i]; // swap parent and child node
            arr[i] = arr[j];
            arr[j] = temp;
            i = j; // make parent node = to larger child
            j = 2 * j; // set j back to left child node
        }
        else
        {
            break;
        }
    }
    return val;
}
void heapsort(int arr[], int n) // deleting an element stores max number at start
{
    for (int i = n; i > 1; i--)
    {
        deleteHeap(arr, i);
    }
}

void printArr(int arr[], int n)
{
    for (int i = 1; i <= n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
void inputArr(int arr[], int n)
{
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
}


int main()
{
    // Declare variables
    int arrHeap[] = { 0,0,0,0,0,0,0,0 };

    // Show application header
    cout << "Welcome to Heap Sorter!" << endl;
    cout << "-----------------------" << endl;

    for (int j = 0; j < 5; j++)
    {
        cout << "\nEnter numbers to heap sort: ";
        inputArr(arrHeap, ARRAYSIZE - 1);
        for (int i = 2; i <= ARRAYSIZE; ++i) // rearranging array to create heap
        {
            insertHeap(arrHeap, i);
        }
        cout << "Max heap: ";
        printArr(arrHeap, ARRAYSIZE - 1);
        cout << "Heap Sorted Array: ";
        heapsort(arrHeap, ARRAYSIZE - 1);
        printArr(arrHeap, ARRAYSIZE - 1);
    }


    // Show application close
    cout << "\nEnd of Heap Sorter" << endl;

}

