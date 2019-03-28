#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <map>
#include <vector>
#include <map>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

int test;
int length, width;
string word("@IEHOVA#"),temp;
vector <string> road;
int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	scanf("%d",&test);
	while (test > 0)
	{
		--test;
		int target = 1;
		scanf("%d%d",&length,&width);
		int step = length - 1;

		for (int i = 0; i < length; ++i)
		{
			cin >> temp;
			road.push_back(temp);
		}
		int pos = road[step].find("@");

		while(target < 8)
		{
			int des = road[step].find(word[target]);

			if (des == -1)
			{
				--step;
				++target;
				printf("forth%c",(target != 8)? ' ':'\n');
			}

			else
			{
				++target;
				if (des > pos)
				{
					for (int i = 0; i < des - pos; ++i)
						printf("right%c", (target != 8) ? ' ' : '\n');

					pos = des;
				}
				else if (des < pos)
				{
					for (int i = 0; i < pos - des; ++i)
						printf("left%c", (target != 8) ? ' ' : '\n');

					pos = des;
				}
			}
		}
		road.clear();
	}
	
	return 0;
}