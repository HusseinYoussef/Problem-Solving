#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int i;
	string givenDirections;
	map<char, int>mp;
//**********************************************************
	cin >> givenDirections;

	if (givenDirections.length() % 2 == 0)
	{
		for (i = 0; i < givenDirections.length(); i++)
			mp[givenDirections[i]]++;

		cout << (abs(mp['R'] - mp['L']) + abs(mp['U'] - mp['D'])) /2;
	}
	else
		cout << "-1";
	return 0;
}