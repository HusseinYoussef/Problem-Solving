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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	vector<string>rat, chw, men;
	string cap;
	sc(n);
	for (int i = 0; i < n; ++i)
	{
		string tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		if (tmp2 == "rat") rat.pb(tmp1);
		else if (tmp2 == "woman" || tmp2 == "child") chw.pb(tmp1);
		else if (tmp2 == "man") men.pb(tmp1);
		else cap = tmp1;
	}

	for (int i = 0; i < sz(rat); ++i) cout << rat[i] << "\n";
	for (int i = 0; i < sz(chw); ++i) cout << chw[i] << "\n";
	for (int i = 0; i < sz(men); ++i) cout << men[i] << "\n";
	cout << cap;
	return 0;
}