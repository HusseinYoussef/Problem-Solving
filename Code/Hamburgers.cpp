#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long LL;

int one_B, one_S, one_C;
int num_B, num_S, num_C;                   // Owned Ingredients
int price_B, price_S, price_C;
long long coins;
//*********************************
bool verify(LL t)                       // Function to determine if the number of sandwiches can be done with the money
{
	LL needed_B = t * one_B - num_B;
	LL needed_S = t * one_S - num_S;
	LL needed_C = t * one_C - num_C;

	if (needed_B < 0) needed_B = 0;
	if (needed_C < 0) needed_C = 0;
	if (needed_S < 0) needed_S = 0;
	 
	LL result = needed_B*price_B + needed_C * price_C + needed_S*price_S;
	if (result <= coins)   // the price Needed 
		return true;
	else
		return false;
}

int main()
{
	string ingredients;
	cin >> ingredients;

	one_B = count(ingredients.begin(), ingredients.end(), 'B');
	one_S = count(ingredients.begin(), ingredients.end(), 'S');
	one_C = count(ingredients.begin(), ingredients.end(), 'C');

	cin >> num_B >> num_S >> num_C;
	cin >> price_B >> price_S >> price_C;
	cin >> coins;
	LL l = 0, r = 10000000000000LL, mid;                // interval for Sandwiches  13  0's  max number of sandwiched can be done 

	while (l < r)                                     // TTTTFFFF      if i could make 100 sandwithes i could make 99 , 98 ,97...
	{
		mid = l + (r - l + 1) / 2;

		if (verify(mid))                             // mid will be number of sandwiches
			l = mid;
		else
			r = mid - 1;
	}                               
	cout << r;                         // r or l   both Equal
	return 0;
}
