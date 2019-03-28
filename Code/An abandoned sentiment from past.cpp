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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int n, k, idx;
	int arr[105];
	int b[105];
	vector<int>vec;

	sc(n); sc(k);
	for (int i = 0; i < n; ++i)
	{
		sc(arr[i]);
		if (arr[i]) vec.pb(arr[i]);
		if (k == 1 && !arr[i])idx = i;
	}
	for (int i = 0; i < k; ++i) sc(b[i]);

	int pre, aft;
	if (k == 1)
	{
		if (idx == 0) pre = -1, aft = arr[1];
		else if (idx == n - 1) pre = arr[idx - 1], aft = INF;
		else pre = arr[idx - 1], aft = arr[idx + 1];
	}
	if (is_sorted(vec.begin(), vec.end()) && k == 1 && sz(vec))
		if (b[0] > pre && b[0] < aft) return puts("No");
	
	return puts("Yes");
	return 0;
}