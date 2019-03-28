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
https://github.com/osama-afifi/Online-Judges-Solutions/blob/master/CodeForces/CodeForces/Pashmak%20and%20Parmida%27s%20problem.cpp
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

const int N = 1e6 + 10;
const int maxBit = (1 << 20) + 10;
int arr[N], BIT[maxBit], n;
map<int, int> freqi, freqj;int freq[N];

void update(int idx, int val)
{
	for (; idx<maxBit; idx += (idx&-idx))
		BIT[idx] += val;
}

int getSum(int idx)
{
	int sum = 0;
	for (; idx; idx -= (idx&-idx)) sum += BIT[idx];
	return sum;
}

//int getRangeSum(int l, int r)
//{
//	return getSum(r) - getSum(l - 1);
//}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	for (int i = 0; i < n; ++i)
	{
		sc(arr[i]);
		freq[i] = ++freqi[arr[i]];
	}
	ll ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		ans += getSum(freq[i] - 1);  // -1 to get smaller elements only not equal
		int f = ++freqj[arr[i]];
		update(f, 1);      // f is freq of j then we update f that we found element less or equal to f
	}
	printf("%lld", ans);
	return 0;
}