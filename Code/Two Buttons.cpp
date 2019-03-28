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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m;
	int sp[10005];
	sc(n); sc(m);
	for (int i = 0; i < 10005; ++i) sp[i] = INF;

	queue<int>q;
	q.push(n);
	sp[n] = 0;
	while (!q.empty())
	{
		int node = q.front();
		int dis = sp[node];
		q.pop();
		if (node * 2 <= 1e4 && dis + 1 < sp[node * 2])
		{
			q.push(node * 2);
			sp[node * 2] = dis + 1;
		}
		if (node - 1 <= 1e4 && dis + 1 < sp[node - 1] && node - 1 > 0)
		{
			q.push(node - 1);
			sp[node - 1] = dis + 1;
		}
	}
	printf("%d", sp[m]);
	return 0;
}