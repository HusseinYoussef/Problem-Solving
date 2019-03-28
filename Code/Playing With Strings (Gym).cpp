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
#define INF					1000000100			
#define llINF				10000000000100
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

string s;
int freq[30];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	sc(t);
	while (t--)
	{
		cin >> s;
		set<char>st;		mem(freq, 0);

		for (int i = 0; i < sz(s); ++i)++freq[s[i] - 'a'], st.insert(s[i]);
		int o = 0;
		for (char c : st) if (freq[c - 'a'] & 1)++o;

		if (sz(s) % 2 == 0 && o) { puts("impossible"); continue; }
		else if(sz(s) % 2 && o != 1) { puts("impossible"); continue; }

		string tmp = "";
		for (char c : st)
		{
			while (freq[c - 'a'] > 1)
			{
				tmp += c;
				freq[c - 'a'] -= 2;
		
			}
		}		
		if (sz(s) & 1)
		{
			char m;
			for (char c : st)
				if (freq[c - 'a']) { m = c; break; }
			cout << tmp;
			cout << m;
			reverse(tmp.begin(), tmp.end());
			cout << tmp;

		}
		else
		{
			cout << tmp;
			reverse(tmp.begin(), tmp.end());
			cout << tmp;
		}
		printf("\n");
	}
	return 0;
}