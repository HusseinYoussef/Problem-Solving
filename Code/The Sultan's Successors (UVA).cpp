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

int k;
bool vis[8][8];
int board[8][8];
int sum = 0;
vector<pair<int, int>>cells;

bool valid(int x,int y)
{
	if (!vis[x][y])
	{
		for (int i = 0; i < cells.size();++i)
			if (abs(cells[i].first - x) == abs(cells[i].second - y) || cells[i].second == y || cells[i].first == x)
				return false;
		return true;
	}
	return false;
}

void rec(int r,int tot)
{
	if (r == 8)
	{
		if (tot > sum)
			sum = tot;
		return;
	}
	int i , j;
	for (i = r, j = 0; j < 8; ++j)
	{
		if (valid(i,j))
		{
			pair<int, int> loc = make_pair(i, j);
			vis[i][j] = 1;
			cells.push_back(loc);
			rec(r + 1,tot + board[i][j]);
			cells.pop_back();
			vis[i][j] = 0;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

	scanf("%d", &k);
	while (k > 0)
	{
		--k; sum = 0;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
			{scanf("%d", &board[i][j]); vis[i][j] = 0;}

		for (int i = 0, j = 0; j < 8; ++j)
			rec(i,0);
		cout << setfill(' ') << setw(5) << sum  << "\n";
	}
	return 0;
}