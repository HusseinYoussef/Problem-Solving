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
#include <numeric>
#include <bitset>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)              scanf("%d",&x)
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

vector<bool>primes(10010, 1);
vector<int>pri;
vector<vector<int>>G(10010);
int sp[10010];
int so, ta;

bool valid(int x,int y)
{
	stringstream ss,bb;
	string a(""), b("");

	ss << x; ss >> a;
	bb << y; bb >> b;
	int cnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (a[i] == b[i])++cnt;
	}
	return cnt == 3;
}

void sieve()
{
	primes[0] = primes[1] = 0;
	for (int i = 2; i*i <= 10000; ++i)
	{
		if (primes[i])
		{
			for (int j = i + i; j <= 10000; j += i)
			{
				primes[j] = 0;
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

	sieve();
	for (int i = 1001; i < 10000; ++i) if (primes[i]) pri.pb(i);

	for (int i = 0; i < sz(pri); ++i)
	{
		for (int j = i + 1; j < sz(pri); ++j)
		{
			if (valid(pri[j] , pri[i]))
			{
				G[pri[i]].pb(pri[j]);
				G[pri[j]].pb(pri[i]);
			}
		}
	}

	int t;
	sc(t);
	while (t--)
	{
		sc(so); sc(ta);

		for (int i = 1000; i <= 10000; ++i)
			sp[i] = INF;
		
		queue<pair<int,int>>q;

		q.push(MP(so,0));
		sp[so] = 0;
		while (!q.empty())
		{
			int n = q.front().first;
			int cst = q.front().second;
			q.pop();

			if (n == ta)break;
			for (int i = 0; i < sz(G[n]); ++i)
			{
				if (cst + 1 < sp[G[n][i]])
				{
					q.push(MP(G[n][i], cst + 1));
					sp[G[n][i]] = cst + 1;
				}
			}
		}
		if (sp[ta] != INF)
			printf("%d\n", sp[ta]);
		else
			printf("Impossible\n");
	}
	return 0;
}