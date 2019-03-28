#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

vector<pair<int, int>>kay, cat;
vector<int>lorry;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int n, v;
	sc(n); sc(v);                      //problem eggsy
	for (int i = 1; i <= n; ++i)
	{
		int t, p; 
		sc(t); sc(p);
		if (t == 1) kay.pb({ p,i });
		else cat.pb({ p,i });
	}
	sort(kay.begin(), kay.end());
	sort(cat.begin(), cat.end());

	int i = sz(kay) - 1, j = sz(cat) - 1, sum = 0;
	while (v > 0 && ( i >= 0|| j >= 0))                  //should I take 1 of Type2  or 2 of Type1 ??!
 	{ 
		if (v % 2 == 1)
		{
			v -= 1;
			if (i < 0)continue;
			lorry.pb(kay[i].second);
			sum += kay[i].first, --i;
		}
		else
		{
			if (((i>=0)?kay[i].first:0) + ((i > 0) ? kay[i - 1].first : 0) > ((j >=0)? cat[j].first:0))    
			{
				lorry.pb(kay[i].second); if (i > 0) lorry.pb(kay[i - 1].second); else ++v;
				sum = sum + ((i >= 0) ? kay[i].first : 0) + ((i > 0) ? kay[i - 1].first : 0);
				i -= 2;
				v -= 2;
			}

			else
			{
				lorry.pb(cat[j].second);
				sum += cat[j].first;
				--j;
				v -= 2;
			}
		}
	}

	printf("%d\n", sum);
	for (int i = 0; i < sz(lorry); ++i) printf("%d ", lorry[i]);
	return 0;
}