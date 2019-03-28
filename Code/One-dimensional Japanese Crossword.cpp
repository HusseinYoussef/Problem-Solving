#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int main()
{
	int n, group = 0, cell = 0;
	vector<int>cells;
	bool flag = false;
	string row;
//******************************//
	cin >> n >> row;

	for (int i = 0; i < n; ++i)
	{
		if (row[i] == 'B')
		{
			++cell;
			if (flag == false)
			{
				flag = true;
				++group;
			}
		}
		else
		{
			if (cell != 0)
				cells.push_back(cell);
			cell = 0;
			flag = false;
		}
		if (i == n - 1 && flag == true)
			cells.push_back(cell);
	}

	printf("%d\n", group);

	if (group != 0)
	{
		for (int i = 0; i < group; ++i)
			printf("%d ", cells[i]);
	}
	return 0;
}