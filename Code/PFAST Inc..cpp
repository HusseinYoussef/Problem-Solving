#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
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

int n, m;
vector<string>vol(20);
vector<pair<string, string>>kids(122);
vector<string> found;

bool valid(string me,vector<string>team)
{
	for(int i =0;i<team.size();++i)
	for (int j = 0; j <m; ++j)
		if ((me == kids[j].first && team[i] == kids[j].second) || (me == kids[j].second && team[i] == kids[j].first))
			return false;
	return true;
}

void rec(int indx, vector<string>v)
{
	if (indx == n)
		return;

	for (int i = indx; i < n; ++i)
	{
		if (valid(vol[i],v))
		{
			v.push_back(vol[i]);
			if (v.size() > found.size())
				found = v;
			rec(i + 1, v);
			v.pop_back();
		}
	}
}

int main() 
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i)
		cin >> vol[i];
	for (int i = 0; i < m; ++i)
		cin >> kids[i].first >> kids[i].second;

	vector<string>team;
	rec(0, team);
	sort(found.begin(), found.end());
	printf("%d\n", found.size());
	for (int i = 0; i < found.size(); ++i)
		cout << found[i] << "\n";
	
	return 0;
}