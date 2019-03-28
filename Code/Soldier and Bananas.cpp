#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int main()
{
	int k_const, money, Bananas;
	int sum = 0;
	cin >> k_const >> money >> Bananas;

	for (int i = 1; i <= Bananas; ++i)
	{
		sum += i*k_const;
	}

	if (sum <= money) cout << "0";
	else
		cout << sum - money;

	return 0;
}