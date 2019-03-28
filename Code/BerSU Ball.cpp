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
#define INF					2000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int b, g;
	vector<pair<int, bool>> boys, girls;
	sc(b);
	for (int i = 0; i < b; ++i)
	{
		int tmp;
		sc(tmp);
		boys.pb({ tmp,0 });
	}
	sc(g);
	for (int i = 0; i < g; ++i)
	{
		int tmp;
		sc(tmp);
		girls.pb({ tmp,0 });
	}
	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());

	int p = 0;
	for (int i = 0; i < b; ++i)
	{
		for (int j = 0; j < g; ++j)
		{
			if (abs(boys[i].first - girls[j].first) < 2 && !girls[j].second)
			{
				boys[i].second = girls[j].second = 1;
				++p;
				break;
			}
		}
	}
	printf("%d", p);
	return 0;
}