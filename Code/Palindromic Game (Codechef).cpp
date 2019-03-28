#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
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

string s, t;
int Afreq[30], Bfreq[30];
int g[30];

int main()  // *** idea came by doing many samples (implementaion) ***
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int T;
	sc(T);
	while (T--)       // each player is trying to win
	{
		cin >> s >> t;
		for (int i = 0; i < 30; ++i)Afreq[i] = Bfreq[i] = g[i] = 0;
		for (int i = 0; i < sz(s); ++i)++Afreq[s[i] - 'a'], ++Bfreq[t[i] - 'a'];

		bool ok = 0;
		for (int i = 0; i < sz(s); ++i)   // first player will try to put a char that the other doesn't have
		{
			if (!Bfreq[s[i] - 'a']) { ok = 1; break; }
		}
		char c;
		if (ok) // if he found such a char
		{
			int mx = 0; 
			for (int i = 0; i < sz(s); ++i)  // he will put a char that has most freq  to be able to play it again to make palindrome   
			{
				if (!Bfreq[s[i] - 'a'] && Afreq[s[i] - 'a'] > mx)
				{
					c = s[i];
					mx = Afreq[s[i] - 'a'];
				}
			}
			--Afreq[c - 'a'];
			++g[c - 'a'];
		}
		else  // if first player didn't find such a char he loses
		{
			puts("B"); continue;
		}

		ok = 0;
		for (int i = 0; i < sz(s); ++i)  // first round to player 2   he will try to put a char that the other player doesn't have
		{
			if (!Afreq[t[i] - 'a']) { ok = 1; break; }
		}
		if (ok) // if he found such a char
		{
			if (Afreq[c - 'a']) { puts("A"); continue; }   // if the first player can put the same char he played at first he wins   -> a c a
		}
		else  // if he didn't find such a char he loses
		{
			puts("A"); continue;
		}
		puts("B");
	}
	
	return 0;
}