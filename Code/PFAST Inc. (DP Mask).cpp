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

const int N = 20;
int n, m; string arr[N], s, t;
map<string, int>mp;
vector<int>sq;
int grid[N][N];
int dp[N][(1 << 17) + 5];

int solve(int idx, int msk)
{
	if (idx == n) return 0;

	int &ret = dp[idx][msk];
	if (~ret) return ret;

	for (int i = 0; i < n; ++i) // haters
	{
		if (msk & (1 << i))
		{
			if (grid[idx][i])
				return ret = max(ret, solve(idx + 1, msk));
		}
	}
	
	return ret = max3(ret, solve(idx + 1, msk), solve(idx + 1, msk | (1 << idx)) + 1);
}

void path(int idx, int msk)
{
	if (idx == n) return;

	bool f = 0;
	for (int i = 0; i < n; ++i)
	{
		if (msk & (1 << i) && grid[i][idx])
		{
			f = 1;
			break;
		}
	}
	if (!f && solve(idx, msk) == solve(idx + 1, msk | (1 << idx)) + 1)
	{
		sq.pb(idx);
		path(idx + 1, msk | (1 << idx));
		return;
	}
	else if(solve(idx, msk) == solve(idx + 1, msk))
	{
		path(idx + 1, msk);
		return;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> arr[i], mp[arr[i]] = i;
	mem(dp, -1);
	while (m--)
	{
		cin >> s >> t;
		int i = mp[s], j = mp[t];
		grid[i][j] = grid[j][i] = 1;
	}

	int ans = solve(0, 0);
	path(0, 0);
	vector<string>vec;
	for (int i : sq)vec.pb(arr[i]);

	sort(all(vec));
	cout << sz(vec) << endl;
	for (int i = 0; i < sz(vec); ++i)cout << vec[i] << endl;

	return 0;
}