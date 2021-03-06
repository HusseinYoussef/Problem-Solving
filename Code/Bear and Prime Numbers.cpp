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
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 1e7 + 5;
int n, m;
int freq[N];
vector<int>prime(N, 1);

void Sieve()
{
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 1e7; ++i)
	{
		if (prime[i])
		{
			prime[i] = freq[i];
			for (int j = i + i; j <= 1e7; j += i)
			{
				prime[j] = 0;
				prime[i] += freq[j];
			}
		}
		prime[i] += prime[i - 1];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		sc(tmp);
		++freq[tmp];
	}
	Sieve();
	sc(m);

	for (int i = 0; i < m; ++i)
	{
		int l, r;
		sc(l); sc(r);
		if (r > 1e7) r = 1e7;
		if (l > 1e7) l = 1e7;
		printf("%d\n", prime[r] - prime[l - 1]);
	}
	return 0;
}