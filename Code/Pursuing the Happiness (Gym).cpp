#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <stdio.h>
#include <map>
#include <unordered_map>
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
typedef vector<vector<int> > VVI;
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int inline max3(int a, int b, int c) { return max(a, max(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }

string s, t;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> s;

	int h = 0;
	t = "happiness";
	for (int i = 0; i <= (int)sz(s) - (int)sz(t); ++i)
	{
		int sum = 0;
		
		for (int j = 0; j < sz(t); ++j)
		{
			if (s[i + j] == t[j]) ++sum;
		}
		if (sum == sz(t))++h;
	}
	
	if (h > 2) return puts("NO");
	if (h == 2)
	{
		int x = -1, y = -1;
		x = s.find(t), y = s.rfind(t);
		puts("YES");
		printf("%d %d", x + 1, y + 2);

	}
	else if (h == 1)
	{
		int x = -1;
		x = s.find(t);
		puts("YES");
		printf("%d %d", x + 1, x + 2);
	}
	else
	{
		puts("YES");
		int x = -1, y = -1;
		x = s.find("p"), y = s.rfind("p");
		 
		if (x != y) printf("%d %d", x + 1, y + 1);
		else printf("1 2");
	}
	return 0;
}