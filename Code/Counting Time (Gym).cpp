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
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int grid[5][5];
bool vis[12];
vector<int>num;
vector<pair<int, int>>zrs;
ll ans;

bool ok(int x,int y)
{
	return (x < 3 && x >= 0 && y < 3 && y >= 0);
}

bool valid()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int cell = grid[i][j];
			bool t1 = 0;
			for (int k = 0; k < 8; ++k)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if (ok(nx, ny))
				{
					if (grid[nx][ny] == cell + 1) t1 = 1;
				}
			}
			if (cell < 9)
			{
				if (!t1)
					return 0;
			}
		}
	}
	return 1;
}

void rec(int idx)
{
	if (idx == sz(zrs))
	{
		if (valid()) ++ans;
		return;
	}
	
	int x = zrs[idx].first, y = zrs[idx].second;
	for (int i = 0; i < sz(num); ++i)
	{
		if (!vis[num[i]])
		{
			vis[num[i]] = 1;
			grid[x][y] = num[i];
			rec(idx + 1);
			vis[num[i]] = 0;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	for (int i = 0; i < 3; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 3; ++j)
		{
			grid[i][j] = s[j] - '0';
			if (grid[i][j])vis[grid[i][j]] = 1;
			else zrs.pb({ i,j });
		}
	}
	for (int i = 1; i <= 9; ++i) if (!vis[i])num.pb(i);

	if (sz(zrs))
		rec(0);
	else
	{
		if (valid()) ++ans;           // in case of the Grid already filled   if filled correctly ans = 1 otherwise ans = 0
	}
			
	printf("%I64d", ans);
	return 0;
}