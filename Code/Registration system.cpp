#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n, i;
	map<string, int>mp;
	string s;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s;
		if (mp[s] == 0)
		{
			cout << "OK" << endl;
			mp[s]++;
		}	
		else
			cout << s << mp[s]++ << endl;
	}

	return 0;
}