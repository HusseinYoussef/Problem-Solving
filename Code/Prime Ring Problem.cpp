#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;
typedef long long ll;
typedef unsigned int uint;

int n , cases = 0;
vector<bool>vis(20, 0);
int elements[20];
vector<bool>prime(30,1);

void sieve()
{
	prime[0] = prime[1] = 0;

	for (int i = 2; i*i <= 29 ;++i)
	{
		if (prime[i])
		{
			for (int j = i+i; j <= 29; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}

void cycle(int k, int c)
{
	if (k == n && prime[elements[k - 1] + 1])
	{
		for (int i = 0; i < n; ++i)
		{
			if(i == n-1)
			printf("%d", elements[i]);
			else
			printf("%d ", elements[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i] && prime[elements[c] + i])
		{
			vis[i] = true;
			elements[c + 1] = i;
			cycle(k + 1, c + 1);
			vis[i] = false;
		}
	}
}

int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	sieve();
	while (cin >> n )
	{
		++cases;
		if (cases > 1) 
			printf("\n");
		elements[0] = 1;
		printf("Case %d:\n", cases);

		cycle(1,0);

	}
	return 0;
}