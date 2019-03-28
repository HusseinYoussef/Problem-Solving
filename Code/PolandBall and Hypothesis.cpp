#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <numeric>
#include <iterator>

using namespace std;

typedef long long LL;
typedef unsigned int uint;


vector<int>prime(1000010, 1);
int n;
void sieve(int t)
{
	prime[0] = prime[1] = 0;

	for (int i = 2; i <= 1000002; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= 1000002; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}

int main()
{
	int m;
	cin >> n;
	sieve(n);
	for (m = 1; m <= 1000; ++m)
	{
		if (!prime[n * m + 1])
		{
			cout << m;
			return 0;
		}
	}
	return 0;
}