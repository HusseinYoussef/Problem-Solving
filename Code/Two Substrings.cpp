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
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif

	string s;
	vector<int>ab, ba;
	cin >> s;

	for (int i = 0; i < sz(s)-1; ++i)
	{
		if (s[i] == 'A' && s[i + 1] == 'B') ab.pb(i);
		else if (s[i] == 'B' && s[i + 1] == 'A') ba.pb(i);
	}
	for (int i = 0; i < sz(ab); ++i)
	{
		for (int j = 0; j < sz(ba); ++j)
		{
			if ((ab[i] != ba[j] + 1) && (ab[i] + 1 != ba[j])) return puts("YES");
		}
	}
	return puts("NO");
}