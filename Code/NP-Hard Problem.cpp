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

vector<vector<int>>G(100010);
int arr[100010];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, E;
	sc(N); sc(E);
	for (int i = 0; i <= N; ++i) arr[i] = -2;
	for (int i = 0; i < E; ++i)
	{
		int from, to;
		sc(from); sc(to);
		arr[from] = arr[to] = -1;           //To mark those nodes who appeared
		G[from].pb(to);                     //which aren't alone
		G[to].pb(from);
	}
	queue<int>q;
	vector<int>A, P;
	for (int i = 1; i <= N; ++i)          
	{
		if (arr[i] == -1)           // only marked Nodes
		{
			q.push(i);                    // 0 for S
			arr[i] = 0;                   // 1 for P
			A.pb(i);
			while (!q.empty())
			{
				int node = q.front();
				q.pop();

				for (int i = 0; i < sz(G[node]); ++i)
				{
					if (arr[G[node][i]] == arr[node])
						return puts("-1");
					if (arr[G[node][i]] == -1)
					{
						arr[G[node][i]] = !arr[node];

						if (arr[G[node][i]] == 1)
							P.pb(G[node][i]);
						else if (!arr[G[node][i]])
							A.pb(G[node][i]);
						q.push(G[node][i]);
					}
				}
			}
		}
	}
	printf("%d\n", sz(A));
	for (int i = 0; i < sz(A); ++i) printf("%d ", A[i]);
	printf("\n%d\n", sz(P));
	for (int i = 0; i < sz(P); ++i) printf("%d ", P[i]);
	return 0;
}