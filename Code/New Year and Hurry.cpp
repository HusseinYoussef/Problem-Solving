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
	int n, k, minutes = 240;
//************************************
	cin >> n >> k;

	minutes -= k;
	int solved = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		if (minutes >= 5 * i)
		{
			minutes -= 5 * i;
			solved++;
		}
		else
			break;
	}

	cout << solved;
	return 0;
}