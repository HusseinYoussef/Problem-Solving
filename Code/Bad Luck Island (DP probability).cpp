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

const int N = 105;
double dp[N][N][N][3];
bool f;

double solve(int r, int s, int p, int type)
{
	if (r < 0 || s < 0 || p < 0) return 0;
	if (r && s == 0 && p == 0) return type == 0;
	if (r == 0 && s && p == 0) return type == 1;
	if (r == 0 && s == 0 && p) return type == 2;

	if (dp[r][s][p][type] == dp[r][s][p][type]) return dp[r][s][p][type];
	double t = 1.0 * (r*s) + (r*p) + (s*p);

	dp[r][s][p][type] = 0;
	return dp[r][s][p][type] = (r*s*1.0 / t)*solve(r, s - 1, p,type) +  (s*p/t) * solve(r,s,p-1,type)  + (r*p/t) * solve(r-1,s,p,type) ;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int r, s, p;
	cin >> r >> s >> p;
	mem(dp, -1);
	for (int i = 0; i < 3; ++i)
	{
		cout << setprecision(12) << fixed <<solve(r, s,p ,i) << " ";
	}
	return 0;
}