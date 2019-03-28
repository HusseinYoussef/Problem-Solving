#include <iostream>
#include <map>

using namespace std;

int main()
{
	int i,white_weight,black_weight;
	char arr[64];
	map<char, int>mp;
//*******************************************
	for (i = 0; i < 64; i++)
	{
		cin >> arr[i];
		if (arr[i] != '.')
			mp[arr[i]]++;
	}

	white_weight = mp['Q'] * 9 + mp['R'] * 5 + mp['B'] * 3 + mp['N'] * 3 + mp['P'] * 1;
	black_weight = mp['q'] * 9 + mp['r'] * 5 + mp['b'] * 3 + mp['n'] * 3 + mp['p'] * 1;

	if (white_weight == black_weight)
		cout << "Draw";
	else if (white_weight > black_weight)
		cout << "White";
	else
		cout << "Black";
	return 0;
}