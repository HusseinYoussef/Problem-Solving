#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int main()
{
	int n, m;
	int common = 0;
	string temp;
	map<string, bool>mp;
//*******************************************
	cin >> n >> m;
	for (int i = 0; i < n; ++i) { cin >> temp; mp[temp] = 1; }
	for (int i = 0; i < m; ++i) { cin >> temp; if (mp[temp])++common; }
	if (n > m) cout << "YES";
	else if (m > n) cout << "NO";
	else { if (common % 2) printf("YES");else printf("NO"); }
	return 0;
}