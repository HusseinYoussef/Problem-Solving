#include <iostream>
#include <string>

using namespace std;

int main()
{
	string stones;
	int stones_num,i,removed = 0;
//********************
	cin >> stones_num;
	cin >> stones;

	i = 0;
	while (i < stones_num - 1)
	{
		if (stones[i] == stones[i + 1])            // if there are 2 consequently stones of the same color
		{                                          // remove one then decrease the number of the stones
			stones.erase(0,1);
			removed++;
			stones_num--;
		}
		else
			i++;
	}

	cout << removed;
	return 0;
}