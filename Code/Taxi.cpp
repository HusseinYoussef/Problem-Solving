#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int Groups, i, taxi = 0, temp;
	int ones = 0, twos = 0, threes = 0;
	//******************************************

	cin >> Groups;

	for (i = 0; i < Groups; i++)
	{
		cin >> temp;

		if (temp == 3) threes++;
		else if (temp == 4) taxi++;
		else if (temp == 2) twos++;
		else ones++;

		if (twos == 2)
		{
			taxi++;
			twos -= 2;
		}
	}
	temp = min(ones,threes);

	threes -= temp;
	ones -= temp;
	taxi += temp;

	if (threes != 0)
	{
		taxi += threes;
		threes = 0;
	}
	
	if (ones > 0 && twos != 0)
	{
		taxi++;
		twos--;
		if (ones == 1) ones -= 1;
		else if (ones >= 2) ones -= 2;
	}
	if (twos != 0)
	{
		twos--;
		taxi++;
	}
	if (ones != 0)
	{
		if (ones <= 4)
		{
			taxi++;
			ones = 0;
		}
		else if (ones > 4 && ones % 4 == 0)
		{
			taxi += ones / 4;
			ones = 0;
		}
		else if (ones > 4 && ones % 4 != 0)
		{
			taxi += (ones / 4) + 1;
			ones = 0;
		}

	}
	cout << taxi;
	return 0;
}



	