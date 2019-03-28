#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <stdio.h>
#include <map>
#include <unordered_map>
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
typedef long double ld;
typedef unsigned int uint;
typedef vector<vector<int> > VVI;
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					2e9+10			
#define llINF				40000000000100
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll inline max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll inline min3(ll a, ll b, ll c) { return min(a, min(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

int n, m;
char grid[55][55];
bool vis[55][55];
int arr[4];
string s;
bool out;

map<int, char>mp;

bool ok(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}
void dfs(int x, int y, int idx)
{
	vis[x][y] = 1;

	if (idx > sz(s)) return;
	if (grid[x][y] == 'E') { out = 1; return; }


	if (mp[s[idx] - '0'] == 'L' && ok(x, y - 1))
	{
		dfs(x, y - 1, idx + 1);
	}
	else if (mp[s[idx] - '0'] == 'R' && ok(x, y + 1))
	{
		dfs(x, y + 1, idx + 1);
	}
	else if (mp[s[idx] - '0'] == 'U' && ok(x - 1, y))
	{
		dfs(x - 1, y, idx + 1);
	}
	else if (mp[s[idx] - '0'] == 'D' && ok(x + 1, y))
	{
		dfs(x + 1, y, idx + 1);
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(m);
	int sx, sy;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'S') sx = i, sy = j;
		}
	}
	for (int i = 0; i < 4; ++i)arr[i] = i;
	cin >> s;
	int ans = 0;

	do
	{
		mp[arr[0]] = 'L';
		mp[arr[1]] = 'R';
		mp[arr[2]] = 'U';
		mp[arr[3]] = 'D';
		out = 0;
		dfs(sx, sy, 0);
		ans += out;
		mem(vis, 0);
	} while (next_permutation(arr, arr + 4));
	cout << ans;
	return 0;
}