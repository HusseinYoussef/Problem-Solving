#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
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
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
#define sc(x)           scanf("%d",&x)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				(v.size())
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lop(i, n)		for(int i=0;i<n;++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define pb					push_back
#define MP					make_pair

int T, D, Q, P;
vector<pair<string, pair<int, int>>> database;
int Que[1002];

void rec(int indx)
{
	if (indx == Q)
		return;
	string name; int cnt = 0;
	lop(i, D)
		if (Que[indx] >= database[i].second.first && Que[indx] <= database[i].second.second)
		{++cnt; name = database[i].first; if (cnt > 1)break;}
	if (cnt == 1) cout << name << "\n";
	else printf("UNDETERMINED\n");
	rec(indx+1);

}

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif

		sc(T); int cnt = 0;
	while (T > 0)
	{
		--T; if (cnt != 0) printf("\n");
		++cnt;
		sc(D);
		database.clear();
		lop(i, D)
		{
			string name; int L, H;
			cin >> name;
			sc(L); sc(H);
			database.push_back(make_pair(name, make_pair(L, H)));
		}
		sc(Q);
		lop(i, Q)
			sc(Que[i]);
		rec(0);
	}
	return 0;
}