#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
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
#include <numeric>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lop(i, n)		for(int i=0;i<n;++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define pb					push_back
#define MP					make_pair

int N, M, f;
int arr[22];
bool vis[22];

bool rec(int indx, int ss, int s)
{
	if (ss == 4) return 1;
	else if (s == 0)  return(rec(0, ss + 1, f));
	else if (indx == M) return 0;
	else
	{
		for(int i=indx ;i<M;++i)
		if (arr[i] <= s && (!vis[i]))
		{
			vis[i] = 1;
			if (rec(i + 1, ss, s - arr[i])) return 1;
			vis[i] = 0;
		}
	}
	return 0;
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	sc(N);
	while (N--)
	{
		scanf("%d", &M); int sum = 0;
		for (int i = 0; i < M; ++i) { scanf("%d", &arr[i]); sum += arr[i]; }

		if (sum % 4 != 0) printf("no\n");
		else
		{
			f = sum / 4;
			memset(vis, 0, 22);
			printf("%s\n", (rec(0, 0, f))? "yes" : "no");
		}
	}

	return 0;
}