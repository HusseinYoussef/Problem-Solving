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
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 1e3 + 5;
vector<bool>prime(N, 1);
vector<int>p;
int n, k;

void sieve()
{
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= 1000; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= 1000; j += i)
				prime[j] = 0;
		}
	}
}

bool valid(int l, int r)
{
	for (int i = l+1; i <= r; ++i)
	{
		if (prime[i])
		{
			if (i == r) return 1;
			else return 0;
		}
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(k);
	sieve();
	for (int i = 2; i <= n; ++i)if (prime[i])p.pb(i);

	int cnt = 0;
	for (int i = 0; i < sz(p); ++i)
	{
		int tst = p[i] - 1;
		for (int j = 0; j < sz(p) && p[j] < tst; ++j)
		{
			if (prime[tst - p[j]])
			{
				if (valid(p[j], tst - p[j]))
				{
					++cnt; break;
				}
			}
			if (cnt == k) break;
		}
	}
	if (cnt < k) return puts("NO");
	return puts("YES");
}