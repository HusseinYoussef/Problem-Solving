#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	string n;
	long long i;
	map<int, long long>mp;
//********************
	cin >> n;                           // stored as a string to be able to check each element

	for (i = 0; i < n.length(); i++)
	{
		mp[n[i]]++;
	}

	if (mp[52] + mp[55] == 4 || mp[52] + mp[55] == 7)  // 52 ASCII code for 4 & 55 ASCII code for 7 the sum should be a lucky number
 		cout << "YES";                                 // 4 or 7
	else
		cout << "NO";
	return 0;
}
