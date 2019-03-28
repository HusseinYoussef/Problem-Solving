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

int n, maxi = 0;
int arr[100005];
pair<int, pair<int, int>> freq[1000005];
vector<int>num;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	for (int i = 1; i <= 1000000; ++i)
	{
		freq[i].second.first = INF;
		freq[i].second.second = 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		sc(arr[i]);
		++freq[arr[i]].first;
		freq[arr[i]].second.first = min(freq[arr[i]].second.first, i);
		freq[arr[i]].second.second = max(freq[arr[i]].second.second, i);
		maxi = max(maxi, freq[arr[i]].first);
	}

	for (int i = 1; i <= n; ++i) if (freq[arr[i]].first == maxi) num.pb(arr[i]); 
	
	int mini = INF, l, r;
	for (int i = 0; i < sz(num); ++i)
	{
		if (freq[num[i]].second.second - freq[num[i]].second.first + 1 < mini)
		{
			mini = freq[num[i]].second.second - freq[num[i]].second.first + 1;
			l = freq[num[i]].second.first;
			r = freq[num[i]].second.second;
		}
	}

	printf("%d %d", l, r);

	return 0;
}