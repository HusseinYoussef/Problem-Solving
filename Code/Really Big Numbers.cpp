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

ll n, s;

bool valid(ll b)
{
	ll tmp = b;
	ll sum = 0;

	while (tmp)
	{
		sum += (tmp % 10);
		tmp /= 10;
	}
	return (b - sum >= s);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	scl(n); scl(s);

	ll l = 0, r = n+1, mid;           // main idea is that    if   x is really big number then (x + 1) is too
	while (l < r)                     // proof  //Since the sum of digits of x  + 1 (let's call it sumd(x + 1)) is not greater than (<= try it!!) sumd(x) + 1, then x + 1 - sumd(x + 1) ≥ x - sumd(x), and if x - sumd(x) ≥ s, then x + 1 - sumd(x + 1) ≥ s. So if x is really big, then x + 1 is really big.
	{
		mid = l + (r - l) / 2;
		if (valid(mid))
			r = mid;
		else 
			l = mid + 1;
	}
	
	printf("%I64d", n - r + 1);
	return 0;
}