#include <iostream>

using namespace std;

int main()
{
	int rooms_num, i;
	int free_rooms = 0, reserved, people_max;
//***************************************

	cin >> rooms_num;

	for (i = 0; i < rooms_num; i++)
	{
		cin >> reserved >> people_max;

		if (reserved + 2 <= people_max)
			free_rooms++;
	}

	cout << free_rooms;
	return 0;
}