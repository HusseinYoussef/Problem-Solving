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

	string arr[3];
	char vow[] = { 'a','e','i','o','u' };
	map<char, bool>mp;
	for (int i = 0; i < 3; ++i)
		getline(cin, arr[i]);
	for (int i = 0; i < 5; ++i) mp[vow[i]] = 1;
	int cnt = 0;

	for (int i = 0; i < sz(arr[0]); ++i)
		if (mp[arr[0][i]]) ++cnt;
	if (cnt != 5) return puts("NO");
	
	cnt = 0;
	for (int i = 0; i < sz(arr[1]); ++i)
		if (mp[arr[1][i]]) ++cnt;
	if (cnt != 7) return puts("NO");

	cnt = 0;
	for (int i = 0; i < sz(arr[2]); ++i)
		if (mp[arr[2][i]]) ++cnt;
	if (cnt != 5) return puts("NO");

	return puts("YES");
}