//==========================================================
//
// Title:      Brute Force Code Cracker
// Course:     CSC 1501
// Lab Number: 8
// Author:     Omar Faruk
// Date:       02/25/21
// Description:
//   Creating a brute force code cracker using a shift cipher
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

void cipherDecode(string cipher)
{
	for (int i = 0; i < 26; i++)
	{
		string decode;

		decode = "";
		for (int j = 0; j < cipher.size(); j++)
		{
			if (isupper(cipher[j]))
			{
				decode += char(int(cipher[j] + i - 65) % 26 + 65);
			}
			else if (islower(cipher[j]))
			{
				decode += char(int(cipher[j] + i - 97) % 26 + 97);
			}
			else
			{
				decode += cipher[j];
			}
		};

		cout << decode << endl;
	}
};
int main()
{

  // Declare variables
	string text;

  // Application header
	cout << "Welcome to Brute Force Code Cracker!" << endl;
	cout << "------------------------------------" << endl;

  // Sample problem
	cout << "\nSample Problem: " << endl;
	text = "Whvwlqj wkh Vbvwhp";
	cipherDecode(text);

  // Problem 1
	cout << "\nProblem 1: " << endl;
	text = "Wkh qljkw lv orqj dqg zh doo suhwhqg wr vohhs";
	cipherDecode(text);

  // Problem 2
	cout << "\nProblem 2: " << endl;
	text = "F xrfqq hnyd mfx gjjs inxhtajwji zsijw ymj gtbqnsl fqqjd";
	cipherDecode(text);

  // Problem 3
	cout << "\nProblem 3: " << endl;
	text = "Yx Drebcnki dro vslbkbi gsvv lo exuxygklvo";
	cipherDecode(text);

  // Problem 4
	cout << "\nProblem 4: " << endl;
	text = "Epht bsf opu bmmpxfe jo uif eph qbsl";
	cipherDecode(text);

  // Problem 5
	cout << "\nProblem 5: " << endl;
	text = "Jrypbzr gb Avtug Inyr";
	cipherDecode(text);

  // Application footer
	cout << "\nEnd of Brute Force Code Cracker";

}
