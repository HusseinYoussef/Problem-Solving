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

string s, t; map<char, int>mp; int cnt = 1; char arr[30];
vector<string>vec; int ind[30]; vector<char>ch;
bool tk[30];
vector<vector<int>>G(30);
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	while (cin >> s && s[0] != '#') 
	{
		for (int i = 0; i < sz(s); ++i)
		{
			if (!tk[s[i] - 'A']) ch.pb(s[i]), tk[s[i] - 'A'] = 1;
			if (!mp[s[i]]) arr[cnt] = s[i], mp[s[i]] = cnt++;
		}
		vec.pb(s);
	}

	for (int i = 0; i < sz(vec) - 1; ++i)
	{
		s = vec[i], t = vec[i + 1];
		for (int j = 0; j < min((int)sz(s), (int)sz(t)); ++j)
		{
			if (s[j] != t[j])
			{
				++ind[mp[t[j]]];
				G[mp[s[j]]].pb(mp[t[j]]);
				break;
			}
		}
	}

	queue<int>q; vector<int>ans; int c = 0;
	for (int i = 0; i < sz(ch); ++i)
	{
		if (ind[mp[ch[i]]] == 0)q.push(mp[ch[i]]);
	}

	while (!q.empty())     // Topological Sort
	{
		int node = q.front();
		q.pop();
		ans.pb(node), c++;

		for (int i = 0; i < sz(G[node]); ++i)
		{
			--ind[G[node][i]];
			if (ind[G[node][i]] == 0)
				q.push(G[node][i]);
		}
	}
	for (int i = 0; i < sz(ans); ++i) printf("%c", arr[ans[i]]);
	printf("\n");
	return 0;
}