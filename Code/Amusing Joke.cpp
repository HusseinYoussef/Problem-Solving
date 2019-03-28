#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int i;
	map<char, int>crmp,check;
	string guest, host, compined;
	bool number_matched =false;
//***********************************************************
	cin >> guest >> host >> compined;

	if (guest.length() + host.length() == compined.length())
	{
		string s = guest+host;
		for (i = 0; i < s.length(); i++)
		{
			crmp[s[i]]++;                           // Getting how many each char appeared
		}
		
		for (i = 0; i < compined.length(); i++)
		{ 
			check[compined[i]]++;                   // Getting how many each char appeared
		}

		for (i = 0; i < compined.length(); i++)
		{ 
			if (check[compined[i]] == crmp[compined[i]])
				number_matched = true;                          // See if appearance number matched or not
			else
			{
				number_matched = false;
				break;
			}
		}
		if (number_matched)
			cout << "YES";
		else
			cout << "NO";
	}

	else
		cout << "NO";

	return 0;
}