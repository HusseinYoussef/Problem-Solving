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
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

int n; string s,t;
int ind[30]; bool tk[30];
vector<vector<int>>G(30);
vector<string>vec;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	while (n--)
	{
		cin >> s;
		vec.pb(s);
	}
	bool ok = 0, f = 1; int cnt = 0, sum = 0;
	for (int i = 0; i < sz(vec) - 1; ++i)
	{
		s = vec[i], t = vec[i + 1];
		for (int j = 0; j < min(sz(s), sz(t)); ++j)
		{
			if (s[j] != t[j])
			{
				if (!tk[s[j] - 'a']) ++sum;
				if (!tk[t[j] - 'a']) ++sum;
				tk[s[j] - 'a'] = tk[t[j] - 'a'] = 1;
				G[s[j] - 'a'].pb(t[j] - 'a');
				++ind[t[j] - 'a'], ok = 1;
				break;
			}
		}
		if (!ok)
			if (sz(s) > sz(t)) f = 0;
	}
	vector<char>ans;
	queue<int>q;
	for (int i = 0; i < 26; ++i)if (ind[i] == 0 && tk[i])q.push(i);
	while (!q.empty())  // topological sort      sorting the chars that affect the names
	{
		int node = q.front();
		q.pop(), ++cnt; ans.pb(node + 'a');
		for (int i = 0; i < sz(G[node]); ++i)
		{
			--ind[G[node][i]];
			if (ind[G[node][i]] == 0)q.push(G[node][i]);
		}
	}
	if (cnt < sum || !f) return puts("Impossible");   // happens when there is a cycle  or  a prefix string with bigger size comes first
	for (int i = 0; i < sz(ans);++i)printf("%c", ans[i]);   // printing the correct order of needed chars
	for (int i = 0; i < 26; ++i)if (!tk[i])printf("%c", i + 'a');  // then print all other chars after them
	return 0;
}