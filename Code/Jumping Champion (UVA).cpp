#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
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

int l, r;
int freq[1000002];
vector<bool>prime(1000005, 1);

void sieve()
{
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= 1000000; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= 1000000; j += i)
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

	int T;
	sc(T);
	sieve();

	while (T--)
	{
		sc(l); sc(r);
		queue<int>q;
		int maxi = 0;
		mem(freq, 0);

		for (int i = l; i <= r; ++i)
		{
			if (prime[i])
			{
				if (sz(q) == 0) q.push(i);
				else
				{
					++freq[i - q.back()];
					maxi = max(maxi, freq[i - q.back()]);
					q.push(i);
				}
			}
		}
		if (sz(q) < 2) printf("No jumping champion\n");
		else
		{
			int cnt = 0,NUM;
			for (int i = 1; i <= r; ++i)
			{
				if (freq[i] == maxi)
				{
					if (cnt == 0) NUM = i;
					++cnt;
				}
			}

			if (cnt > 1)  printf("No jumping champion\n");
			else printf("The jumping champion is %d\n", NUM);
		}
		
	}

	return 0;
}