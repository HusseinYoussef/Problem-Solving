#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned int uint;

int num_ingredients;
LL  k_powder;
LL  needs[100010], owned[100010];

bool possible(LL t)         
{
	LL consumed_powder = 0;
	for (int i = 0; i < num_ingredients; ++i)
	{
		if (t * 1LL*needs[i] - owned[i] > 0)
			consumed_powder += (t * needs[i] - owned[i]);
	}
	if (fabs(consumed_powder) <= k_powder)         // abs to avoid (-) when overflow and use fabs for CF -_-
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

	LL l = 0, r = 10000000000LL, mid;                         // interval for number of Cookies

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