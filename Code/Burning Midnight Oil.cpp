#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int n_lines;
int  k_const;
//*******************************
bool submit(int v)
{
	int sum = v;
	int i = 1, Div = v, x;
	do
	{
		x = pow(k_const, i);
		sum += v / x;
		++i;
	} while (v / x != 0);

	if (sum >= n_lines)
		return true;

	return false;
}

int main()
{
	cin >> n_lines >> k_const;

	int l = k_const, r = n_lines, mid;

	while (l < r)
	{
		mid = l + (r - l) / 2;

		if (submit(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r;
	return 0;
}