#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int temp;
	int i, j = 1;

	for (i = 1; i <=5 && j <=5 ; ++i)
	{
		cin >> temp;
		if (temp == 1)                        // Getting the i,j for 1 (the coordinates for it)
			break;
		if (i == 5)
		{
			i = 0;
			j++;
		}	
	}

	cout << abs(3 - i) + abs(3 - j);         // 3,3  the coordinaes for the mid cell 
	return 0;
}