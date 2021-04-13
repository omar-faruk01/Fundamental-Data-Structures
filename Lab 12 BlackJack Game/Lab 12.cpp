
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main()
{
	// Declare variables
	int total = 0;
	int totalDealer = 0;
	string input;
	bool valid = true;
	int arrHand[10], arrDealer[10]; // Declare arrays
	srand(time(0)); // seed for random num generator
	

	// Show application header
	cout << "Welcome to BlackJack!" << endl;
	cout << "---------------------" << endl;

	// Generate first two random cards
	for (int i = 0; i < 2; i++)
	{
		arrHand[i] = rand() % (10) + 1;
		arrDealer[i] = rand() % (10) + 1;
	}

	// Compute total for cards in hand
	total = arrHand[0] + arrHand[1];
	totalDealer = arrDealer[0] + arrDealer[1];
	int j = 2;

	while (valid)
    {
	  // Printing user and dealer hand
	  cout << "\nHand: ";
	  for (int i = 0; i < j+1; i++)
	  {
		  if (arrHand[i] > 0)
		  {
			  cout << arrHand[i] << " ";
		  }
	  }
	  cout << "Dealer: " << arrDealer[0];


	  // Compute the probability of landing bad and good card
	  int bad = 0, good = 0;
	  if (total > 10)
	  {
		  good = 21 - total;
	  }
	  else
	  {
		  good = 10;
	  }
	 
	  bad = 10 - good;

	  // Displaying probabilty
	  cout << "\nThe probability of getting a bad card is "
		  << bad << "/" << 10 << endl;

	  cout << "The probability of getting a good card is "
		  << good << "/" << 10 << endl;

	  // Take user input for new card
	  cout << "\nHit or Stand? ";
	  cin >> input;

	  // Generating random card
	  if (input == "hit" || input == "Hit")
	  {
		  arrHand[j] = rand() % (10) + 1;
		  if (totalDealer < 17)
		  {
			  arrDealer[j] = rand() % (10) + 1;
			  totalDealer = totalDealer + arrDealer[j];
		  }

		  total = total + arrHand[j];
		  
	  }
	  else
	  {
		  valid = false; // to exit while loop
	  }

	  if (total > 21 || totalDealer > 21 || totalDealer < 0)
	  {
		  valid = false; // to exit while loop
	  }

	  j++;
    }

	// Printing final hand
	cout << "\nFinal Hand: ";
	for (int i = 0; i < j + 1; i++)
	{
		if (arrHand[i] > 0)
		{
			cout << arrHand[i] << " ";
		}
	}
	cout << "Final Dealer: ";
	for (int i = 0; i < j + 1; i++)
	{
		if (arrDealer[i] > 0)
		{
			cout << arrDealer[i] << " ";
		}

	}
	cout << endl <<"\t\t"<< total << "\t\t " << totalDealer << endl;

	//Printing winner
	if (total > 21)
	{
		cout << "\nBust ~ You lost!" << endl;
	}
	else if (totalDealer > 21 )
	{
		cout << "\nBackjack ~ You win!" << endl;
	}
	else if (total > totalDealer)
	{
		cout << "\nBackjack ~ You win!" << endl;
	}
	else
	{
		cout << "\nBust ~ You lost!" << endl;
	}
	

  // Show application close
  cout << "\nEnd of BlackJack" << endl;

}
