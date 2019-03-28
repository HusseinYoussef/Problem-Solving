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

ll fact(ll n)
{
	if (n < 1) return 1;
	
	return n * fact(n - 1);
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string s; ll ans = 0;
	
	cin >> s;

	for (int i = 0; i < sz(s)-1; ++i)
	{
		for (int j = i + 1; j < sz(s); ++j)
		{
			map<char, pair<int,int>>mp;
			set<char>st;
			string tmp = s.substr(i, j - i + 1);

			for (int k = 0; k < sz(tmp); ++k)
			{
				++mp[tmp[k]].first;
				st.insert(tmp[k]);
			}
			set<char>::iterator it;
			int odd = 0,tot = 0;

			for (it = st.begin(); it != st.end(); ++it)
			{
				if (mp[*it].first % 2 != 0) { ++odd; mp[*it].second = (mp[*it].first - 1) / 2; }
				else mp[*it].second = mp[*it].first / 2;
				tot += mp[*it].second;
			}
			
			if (odd < 2)
			{
				ll m = fact(tot);
				for (it = st.begin(); it != st.end(); ++it)
				{
					m /= fact(mp[*it].second);
				}
				ans += m;
			}
		}
	}

	cout << ans + sz(s);
	return 0;
}