#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <vector>
#include <queue>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;

int visit[105][105], arr[105][105];
void floyd(int n)
{
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
}
int fri[15];
int main()
{
	int t;
	cin >> t;
	int k = 1;
	while (t--)
	{
		int n, m, f;
		scanf("%d%d%d", &n, &m, &f);
		for(int i = 1 ; i<=n ; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if (i == j) arr[i][j] = 0;
				else arr[i][j] = 1e8;
			}
		for (int i = 0; i < m; ++i)
		{
			int u, v, c;
			scanf("%d%d%d", &u, &v , &c);
			arr[u][v] = arr[v][u] =  c;
		}
		floyd(n);
		for (int i = 0; i < f; ++i) scanf("%d", &fri[i]);
		sort(fri, fri + f);
		int ans = 1e9;
		do
		{
			int sum = 0;
			for (int i = 0; i < f; ++i)
			{
				if (!i) sum += arr[1][fri[i]];
				else sum += arr[fri[i]][fri[i-1]];
				if (i == f - 1) sum += arr[fri[i]][n];
			}
			ans = min(ans, sum);
		} while (next_permutation(fri, fri + f));
		printf("Case %d: %d\n",k++ ,  ans);
	}
	return 0;
}