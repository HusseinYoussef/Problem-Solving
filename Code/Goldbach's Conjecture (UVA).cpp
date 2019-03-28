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
vector<int>prime(1000002, 1);

void Sieve()
{
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 1000; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= 1000000; j += i)
				prime[j] = 0;
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
	while (sc(n) && n)
	{
		bool fun = false;
		for (int i = 3; i < n; ++i)
		{
			if (prime[i] && prime[n - i])
			{
				printf("%d = %d + %d\n", n, i, n - i);
				fun = 1;
				break;
			}
		}
		if (!fun) printf("‘Goldbach's conjecture is wrong.\n");
	}

	return 0;
}