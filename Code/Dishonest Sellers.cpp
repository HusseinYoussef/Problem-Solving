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

const int N = 2e5 + 10;
pair<int,int> arr[N];
pair<int, pair<int, int>>G[N];
int n, k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(k);
	for (int i = 0; i < n; ++i) sc(arr[i].first);
	for (int i = 0; i < n; ++i)
	{
		sc(arr[i].second);
		G[i] = { abs(arr[i].second - arr[i].first),{arr[i].first,arr[i].second} };
	}
	sort(G, G + n);
	sort(arr, arr + n);

	ll ans = 0;
	for (int i = 0; i < n; ++i)                 // first take the cheaper while the discounts
	{
		if (arr[i].first < arr[i].second)
		{
			--k;
			ans += arr[i].first;
		}
	}
	k = max(k, 0);
	for (int i = 0; i < n; ++i)
	{
		if (G[i].second.first >= G[i].second.second)      // if k > 0 then buy the ones with lowest difference between price during discounts
		{                                                 // and after discounts
			if (k)
			{
				ans += G[i].second.first, --k;
			}
			else                                         // if k <=0 buy the rest 
				ans += G[i].second.second;
		}
	}

	printf("%I64d", ans);
	return 0;
}