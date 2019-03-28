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
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 15;
pair<int, int>grid[N][N];
pair<int, int>sp[N][N];
int n, m;

bool valid(int x, int y)
{
	return  (x >= 0 && x < n && y >= 0 && y < m);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	sc(t);
	while (t--)                  // Dijkstra
	{
		sc(n); sc(m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				sc(grid[i][j].first);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				sc(grid[i][j].second);
			}
		}
		for (int i = 0; i < N; ++i)for (int j = 0; j < N; ++j) sp[i][j].first = sp[i][j].second = INF;
		priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>>pq;
		sp[0][0].first = sp[0][0].second = 0;
		pq.push({ {grid[0][0].first,grid[0][0].second},{0,0} });
		
		while (!pq.empty())
		{
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			int pf = pq.top().first.first;
			int pt = pq.top().first.second;

			pq.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (valid(nx, ny) && pf + grid[nx][ny].first < sp[nx][ny].first)
				{
					pq.push({ {pf + grid[nx][ny].first,pt + grid[nx][ny].second},{nx,ny} });
					sp[nx][ny].first = pf + grid[nx][ny].first;
					sp[nx][ny].second = pt + grid[nx][ny].second;
				}
			}

		}

		printf("%d %d\n", sp[n - 1][m - 1].first, sp[n - 1][m - 1].second);
	}
	return 0;
}