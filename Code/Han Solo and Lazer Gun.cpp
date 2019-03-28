#include <iostream>
#include <map>
using namespace std;

int main()
{
	int trooper_num, gun_x, gun_y, i;
	int shots = 0, trooper_x, trooper_y;
	double slope;
	bool undefined = false;
	map<double, bool>mp;
//***********************************************

	cin >> trooper_num >> gun_x >> gun_y;
	
	for (i = 0; i < trooper_num ; i++)
	{
		cin >> trooper_x >> trooper_y;

		if ((trooper_x - gun_x) != 0)                                            // avoiding the undefined slope 1/0  (special case)
		{
			if (mp[(trooper_y - gun_y) / (double)(trooper_x - gun_x)] == 0)            // Getting the slope
			{                                                                          // and checking if it was seen before
				mp[(trooper_y - gun_y) / (double)(trooper_x - gun_x)] = 1;
				shots++;
			}
		}
		else if (!undefined)                                                // in case of undefined slope
		{
			shots++;
			undefined = true;
		}
	}

	cout << shots;
	return 0;
}