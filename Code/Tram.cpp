#include <iostream>

using namespace std;

int main()
{
	int n_stops_num;
	int exit, enter;
	int inside = 0;
	int max = 0;
//**********************************

	cin >> n_stops_num;

	for (int i = 0; i < n_stops_num; i++)
	{
		cin >> exit >> enter;

		inside = inside - exit + enter;

		if (inside > max)
			max = inside;
	}

	cout << max;
	return 0;
}