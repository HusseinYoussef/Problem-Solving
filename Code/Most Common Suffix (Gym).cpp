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
#define sz(v)				((int)v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                 1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					2e9+10			
#define llINF				40000000000100
#define WHITE 0
#define GRAY 1
#define BLACK 2
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll inline max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll inline min3(ll a, ll b, ll c) { return min(a, min(b, c)); }
ll power(ll x, ll p) { if (p == 0) return 1; else if (p % 2 == 0) return power(1LL * x*x, p / 2); else return 1LL * x*power(1LL * x*x, (p - 1) / 2); }
ll GCD(ll a, ll b) { if (b == 0) return a; return GCD(b, a%b); }

const int MOD = 1000000007;
const int N = 1e5 + 5;
int trie[N][26];
char str[(int) 1e5];
int nxt;
int length[N], mx[N];

void init()
{
	mem(trie, -1);
	nxt = 0;
	mem(mx, 0);
	mem(length, 0);    // how many times i reached this node
}
void insert()  // Trie
{              
	int node = 0;
	int n = strlen(str);
	for (int i = n - 1, j = 1; i >= 0; --i, ++j)
	{
		if (~trie[node][str[i] - 'a'])          // if node exists  move to it
			node = trie[node][str[i] - 'a'];
		else  // else create it and move to it
		{
			trie[node][str[i] - 'a'] = ++nxt;
			node = nxt;
		}
		++length[node];  // increment the counter of the node
		mx[j] = max(mx[j], length[node]);    // j represents the level  level 2 = suffix of length 2   -> get max length of each level
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int t;
	sc(t);
	while (t--)
	{
		init();
		int n, q;
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", str);
			insert();
		}
		int x;
		while (q--)
		{
			sc(x);
			printf("%d\n", mx[x]);
		}
	}

}