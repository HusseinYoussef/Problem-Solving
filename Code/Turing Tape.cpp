#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
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
#include <numeric>
#include <bitset>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF				10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int bitrev(char c)
{
	int ASCII = c;
	bitset<8>bs(ASCII);
	int j = 7;
	ASCII = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (bs[i])
			ASCII += pow(2, j);
		--j;
	}
	return ASCII;
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	string s;
	getline(cin, s);
	int pre = 0;
	for (int i = 0; i < sz(s); ++i)
	{
		int curr = bitrev(s[i]);
		int ans = pre - curr;
		while (ans < 0) ans += 256;
		ans %= 256;
		printf("%d\n", ans);
		pre = curr;
	}
	return 0;
}