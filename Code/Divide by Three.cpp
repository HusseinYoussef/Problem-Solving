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

string s, x, y, t;

string fix(string b)
{
	bool f = 0;
	for (int i = 0; i < sz(b); ++i)
	{
		f = 1;
		if (b[i] != '0')
		{
			string tmp = b.substr(i, sz(b) - i);
			return  tmp;
		}
	}
	if (f) return "0";
	return b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> s; int sum = 0;
	for (int i = 0; i < sz(s); ++i) sum += s[i] - '0';

	if (sum % 3 == 0) return cout << fix(s), 0;
	x = y = s;
	bool f1 = 0, f2 = 0;
	if (sum % 3 == 1)
	{
		for (int i = sz(x) - 1; i >= 0; --i)
		{
			if ((x[i] - '0') % 3 == 1)
			{
				x.erase(i, 1);
				f1 = 1;
				break;
			}
		}
		int cnt = 0;
		for (int i = sz(y) - 1; i >= 0 && cnt < 2; --i)
		{
			if ((y[i] - '0') % 3 == 2)
			{
				y.erase(i, 1);
				++cnt;
			}
		}
		f2 = cnt == 2;
		if (!f1) x = y;
		if (!f2)y = x;
		x = fix(x), y = fix(y);
		if (sz(x) > sz(y))t = x;
		else t = y;
	}
	else if (sum % 3 == 2)
	{
		for (int i = sz(x) - 1; i >= 0; --i)
		{
			if ((x[i] - '0') % 3 == 2)
			{
				x.erase(i, 1);
				f1 = 1;
				break;
			}
		}
		int cnt = 0;
		for (int i = sz(y) - 1; i >= 0 && cnt < 2; --i)
		{
			if ((y[i] - '0') % 3 == 1)
			{
				y.erase(i, 1);
				++cnt;
			}
		}
		f2 = cnt == 2;
		if (!f1) x = y;
		if (!f2)y = x;
		x = fix(x), y = fix(y);
		if (sz(x) > sz(y))t = x;
		else t = y;

	}
	if (sz(t) == 0) return puts("-1");
	cout << fix(t);
	return 0;
}