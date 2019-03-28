#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i;
	string input;
	bool accident;
//******************************************
	cin >> input;

	for (i = 1; i < input.length(); i++)
	{
		if (input[i] >= 65 && input[i] <= 90)                // Checking if all letter except the first are Upper
			accident = true;                                 // So accident is true when all except the first are Upper
		else                                                 // Otherwise print the string Unchanged
		{
			cout << input;
			return 0;
		}
	}
	
	if (accident && (input[0] >= 65 && input[0] <= 90))             // if the first char is Upper 
	{                                                               // and all Other letter are Upper (accident = true)
		for (i = 0; i < input.length(); i++)                        // the change all to LowerCase
			input[i] = tolower(input[i]);
	}
	else if (accident && (input[0] >= 97 && input[0] <= 122))       // if the first char is Lower and the rest are Upper
	{                                                               // Change the first into Upper and the rest into Lower
		input[0] = toupper(input[0]);
		for (i = 1; i < input.length(); i++)
			input[i] = tolower(input[i]);
	}
	cout << input;
	return 0;
}