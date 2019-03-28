#include <iostream>
#include <string>

using namespace std;

int main()
{
	string wordy, hi("hello");
	int i, j = 0, count = 0;
//*********************************
	cin >> wordy;

	for (i = 0; i < wordy.length(); i++)
	{
		if (wordy[i] == hi[j])
		{
			count++;
			j++;
		}
	}

	if (count == 5)             // when count = 5 then all 5 letters found
		cout << "YES";
	else
		cout << "NO";

	return 0;
}