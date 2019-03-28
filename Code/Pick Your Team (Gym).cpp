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
#define INF					1000000100			
#define llINF				10000000000100
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

const int N = 1e2 + 10;
int n;
int pw[N], arr[N];
ll dp[N][N];

ll solve(int idx, int rem , bool t)     //DP solution   every one will be taken either by me or them
{
	if (idx > n)
	{
		if (rem == n / 2) return 0;    // in the end my team will consist of n/2 
		else return -INF;
	}

	ll &ret = dp[idx][rem];
	if (~ret) return ret;

	ret = -INF;
	if (!t)  // t = 0 --> means this one can be taken by me or them
	{
		ret = max3(ret, solve(idx + 1, rem, 0) - pw[arr[idx]], solve(idx + 1, rem + 1, 1) + pw[arr[idx]]);
	}
	else  // t = 1 --> means that i took the last one so this one must be taken by them
	{
		ret = solve(idx + 1, rem, 0) - pw[arr[idx]];
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	sc(n); mem(dp, -1);
	for (int i = 1; i <= n; ++i)sc(pw[i]);
	for (int i = 1; i <= n; ++i)sc(arr[i]);

	cout << solve(1, 0, 0);
	return 0;
}

//int main()       //  *** Another Greedy solution using Priority Queue ***
//{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//	sc(n); ll sum = 0;
//	for (int i = 1; i <= n; ++i)sc(pw[i]), sum += pw[i];  
//	for (int i = 1; i <= n; ++i)sc(arr[i]);

//	priority_queue<int, vector<int>, greater<int>>pq;
//	for (int i = 2; i <= n; i += 2) 
//	{
//		pq.push(pw[arr[i - 1]]);      // take the first one so the the martian will take the next
//		if (pq.top() < pw[arr[i]])
//		{
//			pq.pop();
//			pq.push(pw[arr[i]]);
//		}
//	}
//	ll ans = 0;
//	while (!pq.empty())
//	{
//		ans += pq.top();
//		pq.pop();
//	}
//	printf("%lld", ans - (sum - ans));
//	return 0;
//}