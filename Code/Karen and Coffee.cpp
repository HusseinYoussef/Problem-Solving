#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, k, q;
int arr[200005], prefix[200005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n); sc(k); sc(q);
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		sc(l); sc(r);

		++arr[l];
		--arr[r + 1];                      //important nice Trick   check Tricks.txt
	}
	for (int i = 1; i <= 200000; ++i)arr[i] += arr[i - 1];
	for (int i = 1; i <= 200000; ++i) prefix[i] = prefix[i - 1] + (arr[i] >= k);

	while (q--)
	{
		int a, b;
		sc(a); sc(b);

		printf("%d\n", prefix[b] - prefix[a - 1]);
	}

	return 0;
}