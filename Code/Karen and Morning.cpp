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

	string s;
	cin >> s;

	int h, m;
	stringstream ss(s.substr(0, 2)),yy(s.substr(3, 2));
	ss >> h;
	yy >> m;
	
	int i = h, j = m, ans = 0;
	for (; i <= 23;++i)
	{
		for (; j <= 59; ++j)
		{
			if ((i / 10 == j % 10) && (i % 10 == j / 10))
			{
				printf("%d", ans);
				return 0;
			}
			++ans;
			if (j == 59)
			{
				j = 0;
				break;
			}
		}
		if (i == 23) i = -1;
	}

	return 0;
}