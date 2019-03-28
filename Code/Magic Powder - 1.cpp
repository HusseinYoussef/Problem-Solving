#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int num_ingredients, k_powder;
int needs[1010], owned[1010];

bool possible(int t)         // uint gave me errors   (so don't use unsigned while there is operations on them (-), (+))
{  
	int consumed_powder = 0;
	for (int i = 0; i < num_ingredients; ++i)
	{          
		if (t * needs[i] - owned[i] > 0)
			consumed_powder += (t * needs[i] - owned[i]);
	}
	if (consumed_powder <= k_powder)
		return true;
	else
	return false;

}
int main()
{
	cin >> num_ingredients >> k_powder;

	for (int i = 0; i < num_ingredients; ++i)
		cin >> needs[i];
	for (int i = 0; i < num_ingredients; ++i)
		cin >> owned[i];

	uint l = 0, r = 10000,mid;                    // interval for number of Cookies

	while (l < r)                                 // TTTFFF 
	{
		mid = l + (r - l + 1) / 2;                // Will get the Last True the max number of cookies can be baked
		if (possible(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l;
	return 0;
}