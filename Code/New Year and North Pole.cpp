#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int main()
{
	int away = 0, n, t;
	string dir;
//**********************************
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> t >> dir;
		
		if (dir != "South" && away == 0 || dir != "North" && away == 20000)
		{
			cout << "NO"; return 0;
		}
		if (dir == "South")
		{
			if (away + t > 20000)
			{
				cout << "NO";
				return 0;
			}
			away += t;
		}
		if (dir == "North")
		{
			if (away - t < 0)
			{
				cout << "NO";
				return 0;
			}
			away -= t;
		}
	}
	if (away == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}