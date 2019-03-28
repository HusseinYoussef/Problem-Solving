#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int num, time,i,j;
	string que;
//******************************
	cin >> num >> time >> que;
	if (num > 1)
	{
		for (i = 0; i < time; i++)
		{
			for (j = 1; j < num; j++)
			{
				if (que[j] == 'G' && que[j - 1] == 'B')
				{
					swap(que[j], que[j - 1]);
					j++;
				}
			}
		}
		cout << que;
	}
	else if (num == 1)
		cout << que;
	return 0;
}