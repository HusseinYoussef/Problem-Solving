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

int n, pre = 0;
int a[1005], b[1005], p[1005];
vector<int>num;
bool vis[1005];

bool valid()
{
	int na = 0;
	set<int>st;

	for (int j = 0; j<n; ++j)
	{
		if (a[j] == p[j]) ++na;
		st.insert(p[j]);
	}
	return (sz(st) == n && na == n - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int v;
	sc(n);
	for (int i = 0; i < n; ++i)sc(a[i]);
	for (int i = 0; i < n; ++i)
	{
		sc(b[i]);
		p[i] = b[i];
		if (vis[p[i]]) v = p[i];
		vis[p[i]] = 1;
	}
	vis[v] = 0;
	for (int i = 0; i < n; ++i)if (b[i] == v) num.pb(i);
	
	int tmp1 = p[num[0]], tmp2 = p[num[1]]; 
	for (int j = 1; j <= n; ++j)
	{
		if (!vis[j])
		{
			vis[j] = 1;
			p[num[0]] = j;
			for(int k = 1;k<=n;++k)
			{
				if (!vis[k])
				{
					vis[k] = 1;
					p[num[1]] = k;
					break;
				}
			}
			if (valid())
				break;
			else
			{
				vis[p[num[0]]] = vis[p[num[1]]] = 0;
				p[num[0]] = tmp1;
				p[num[1]] = tmp2;
			}
		}
	}
	
	
	for (int i = 0; i < n; ++i) printf("%d ", p[i]);
	return 0;
}