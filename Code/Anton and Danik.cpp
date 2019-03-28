#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n, i;
	string s;
	map<char, int>mp;
//********************

	cin >> n >> s;

	for (i = 0; i < n; i++)
		mp[s[i]]++;
	
	if (mp['D'] > mp['A'])
		cout << "Danik";
	else if (mp['A'] > mp['D'])
		cout << "Anton";
	else
		cout << "Friendship";


	return 0;
}