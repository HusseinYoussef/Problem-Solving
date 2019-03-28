#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <numeric>
#include <bitset>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n;
vector<bool>prime(10005, 1);
vector<int>primes;

void Sieve()
{
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 100; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= 10000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	Sieve();
	for (int i = 2; i <= 10000; ++i) if (prime[i]) primes.pb(i);
	int T;
	sc(T);

	while (T--)
	{
		sc(n);

		int maxi = 0, pr;       // Note that P = 1 that the best to get the max Difference
		                        // now find the x that primes[i] <= n && 2*primes[i] > n
		for (int i = 0; i < sz(primes) && primes[i] <= n; ++i)
		{
			if (primes[i] <= n && 2*primes[i] > n)
			{
				int tmp = n - (primes[i]);
				if (tmp > maxi)
				{
					maxi = tmp;
					pr = primes[i];
				}
			}
		}
		printf("%d\n", pr);
	}

	return 0;
}