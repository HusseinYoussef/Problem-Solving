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
#define sc(x)               scanf("%d",&x)
#define scl(x)              scanf("%lld",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define mem(v, d)			memset(v, d, sizeof(v))
#define EPS                           1e-9
#define pb					push_back
#define MP					make_pair
#define PI                  3.14159265
#define INF					1000000100			
#define llINF				10000000000100
const char letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

const int N = 3e6 + 10;
int p[N];
char arr[N];
int n, k, lst;
string s;

int find(int u)
{
	if (u == p[u])
		return u;
	return p[u] = find(p[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	sc(n);
	for (int i = 0; i < N; ++i)p[i] = i;
	for (int i = 0; i < n; ++i)             // The problem is that we don't want to go over already written chars
	{                                       // so we have each index pointing the next empty index to write in it   p array
		cin >> s;                           // so we go to it directly    (dsu)
		sc(k); 
		int pos;
		while (k--)
		{
			sc(pos);
			--pos;
			lst = max(lst, pos + (int)sz(s) - 1);

			int idx = find(pos);
			while (idx - pos < sz(s))
			{
				arr[idx] = s[idx - pos];
				p[idx] = find(idx + 1);
				idx = find(idx + 1);
			}
		}
	}
	for (int i = 0; i <= lst; ++i)
	{
		(arr[i]) ? putchar(arr[i]) : putchar('a');
	}
	return 0;
}