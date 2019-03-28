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

int n;
map<string, string>mp;
map<string, bool>ex;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	sc(n);
	for (int i = 0; i < n; ++i)
	{
		string to, tmp, from;
		cin >> to >> tmp >> from;

		for (int i = 0; i < sz(to); ++i)to[i] = tolower(to[i]);
		for (int i = 0; i < sz(from); ++i)from[i] = tolower(from[i]);

		ex[to] = ex[from] = 1;
		mp[to] = from;
	}
	int ans = 0;
	map<string, bool>::iterator it;
	for (it = ex.begin(); it != ex.end(); ++it)
	{
		string tmp = it->first;
		int sum = 0;
		while (mp.count(tmp))
		{
			++sum;
			tmp = mp[tmp];
		}
		ans = max(ans, sum);
	}
	
	printf("%d", ans + 1);
	return 0;
}