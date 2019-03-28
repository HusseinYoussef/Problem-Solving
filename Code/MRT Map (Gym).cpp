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
char letters[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 1e4 + 5;
int n, m, s, e;
vector<vector<int>>G(N);
string arr[N];
int sp[N];

int getcst(string from, string to)
{
	int c = 0;

	for (int i = 0; i < 26; ++i)
	{
		char chk = letters[i];
		for (int j = 0; j < sz(from); ++j)
		{
			if (chk == tolower(from[j]))
			{
				for (int k = 0; k < sz(to); ++k)
				{
					if (chk == tolower(to[k]))
					{
						++c; break;
					}
				}
				break;
			}
		}
	}
	return c;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	sc(n); sc(m);
	for (int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;

		arr[i] = s;
	}
	for (int i = 0; i < m; ++i)
	{
		int from, to;
		sc(from); sc(to);

		G[from].pb(to);
		G[to].pb(from);
	}
	sc(s); sc(e);
	for (int i = 1; i < N; ++i)sp[i] = INF;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

	q.push({ 0,s });
	sp[s] = 0;

	while (!q.empty())
	{
		int node = q.top().second;
		int cst = q.top().first;

		q.pop();
		if (node == e)break;

		for (int i = 0; i < sz(G[node]); ++i)
		{
			int cost = getcst(arr[node], arr[G[node][i]]);

			if (cst + cost < sp[G[node][i]])
			{
				q.push({ cst + cost ,G[node][i] });
				sp[G[node][i]] = cst + cost;
			}
		}

	}
	printf("%d", sp[e]);
	return 0;
}