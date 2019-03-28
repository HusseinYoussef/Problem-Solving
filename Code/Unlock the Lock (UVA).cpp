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
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int L, U, R;
int arr[15];
int sp[10005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int cases = 1;
	while (scanf("%d%d%d", &L, &U, &R) && (L || R || U))
	{
		for (int i = 0; i < R; ++i)sc(arr[i]);
		for (int i = 0; i <= 10000; ++i)sp[i] = INF;
		queue<int>q;

		q.push(L);
		sp[L] = 0;
		while (!q.empty())            //BFS
		{
			int node = q.front();
			int cst = sp[node];

			q.pop();
			if (node == U) break;
			for (int i = 0; i < R; ++i)
			{
				if (cst + 1 < sp[(node + arr[i]) % 10000])
				{
					q.push((node + arr[i]) % 10000);
					sp[(node + arr[i]) % 10000] = cst + 1;
				}
			}
		}
		if (sp[U] != INF) printf("Case %d: %d\n", cases++, sp[U]);
		else printf("Case %d: Permanently Locked\n", cases++);
	}

	return 0;
}