#include <iostream>
#include <string>
using namespace std;

int main()
{
	string present1, present2,transform1,transform2;
	int i; 
	bool equal;
//*********************************

	cin >> present1 >> present2;

	for (i = 0; i < present1.length(); i++)
	{
		if (tolower(present1[i]) != tolower(present2[i]) )        // uppercase letters and lowercase letters are the same
		{
			equal = false;
			break;
		}
		else
			equal = true;
	}

	for (i = 0; i < present1.length(); i++)
	{
		transform1 += tolower(present1[i]);           //changing all chars to lowercase to make the comparison easier
		transform2 += tolower(present2[i]);
	}

	if (!equal)
	{
		if (transform1 < transform2)
		{
			cout << "-1";  return 0;
		}
		else if(transform2 < transform1)
		{
			cout << "1"; return 0;
		}
	}
   else
	   cout << "0";
	return 0;
}