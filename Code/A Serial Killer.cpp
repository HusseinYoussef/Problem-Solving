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
#define EPS                             1e-9
#define pb					push_back
#define MP					make_pair
#define INF					1000000100			
#define llINF					10000000000100
const int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int main()
{
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif
	string vic1, vic2;
	int n;
	vector<pair<string, string>>vec(1010);
	cin >> vic1 >> vic2 >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	cout << vic1 << " " << vic2 << "\n";
	for (int i = 0; i < n; ++i)
	{
		if (vec[i].first == vic1)
			vic1 = vec[i].second;
		else
			vic2 = vec[i].second;
		cout << vic1 << " " << vic2 << "\n";
	}
	return 0;
}