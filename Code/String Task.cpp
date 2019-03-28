#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	string input;

	cin >> input;

	for (int i = 0; i < input.length(); ++i)
	{
		char temp = tolower(input[i]);

		if (temp != 'a' && temp != 'o' && temp != 'y' && temp != 'e' && temp != 'u' && temp != 'i')
		{
			cout << '.' << temp;
		}
	}


	return 0;
}