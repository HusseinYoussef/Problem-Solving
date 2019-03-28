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

	char alph[] = { 'a','b','c','d','e','f','h','g','i','j','k','l','m','n','o','p','s','r','q','t','u','w','v','x','y','z' };
	string s;
	cin >> s;

	for (int i = 0; i <= sz(s); ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			string tmp = s.substr(0, i);
			tmp += alph[j];
			tmp += s.substr(i, sz(s) - i);
			string tmp2 = tmp;
			reverse(tmp2.begin(), tmp2.end());
		
			if (tmp2 == tmp) { cout << tmp; return 0; }
		}

	}
	return puts("NA");
}