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
	
	char vow[] = { 'a','e','o','u','i','y' };
	int pat[110];
	string txt[110];
	map<char, bool>mp;
	int n;

	sc(n);
	for (int i = 0; i < n; ++i)	sc(pat[i]);
	cin.ignore();
	for (int i = 0; i < n; ++i) getline(cin, txt[i]);
	for (int i = 0; i < 6; ++i) mp[vow[i]] = 1;

	for (int i = 0; i < n; ++i)
	{
		int num = 0;
		for (int j = 0; j < sz(txt[i]); ++j)
		{
			if (mp[txt[i][j]])
				++num;
		}
		if (num != pat[i]) return puts("NO");
	}

	return puts("YES");
}