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
#define sz(v)				(v.size())
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
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }

const int N = 150;
ll n;
ll dp[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	scl(n);
	dp[0] = 1, dp[1] = 2;          // f(N) -> to win N match we have to play N-1 and beat a guy who played N-2 (or N-1) but minimize so is N-2
	int i;                        // so f(N) = f(N-1)+f(N-2)  fibonacci
	for (i = 2;; ++i)             // f(N) will represent the people i killed to win N Match
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 1e18) break;
	}
	ll l = 1, r = i, mid;
	while (l < r)
	{
		mid = l + (r - l + 1) / 2;
		if (dp[mid] > n) r = mid - 1;
		else l = mid;
	}
	printf("%lld", l);
	return 0;
}


//Assuming we want a guy to have played n  + 1 matches:
//First of all, he must have played exactly n matches.
//Secondly, he must have beaten someone else who had played at least n - 1 matches.
//It is obvious that we want to minimize the number of matches used to maximize the answer.Therefore, we just assume that the guy that was beaten had played n  - 1 matches before.
//Thus the recurrence formula comes to the surface, which is F(n  + 1) = F(n) + F(n  - 1), where F(n) represents the number of people we need to have one guy who has played n matches.
//The base case are F(0) = 1, F(1) = 2.