#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
	int heroStrength, n,i,bonus,dragonS;
	bool next = false;
	map<int, int> mpbonus;
	set<int>st;
//************************************
	cin >> heroStrength >> n;

	for (i = 0; i < n; i++)
	{
		cin >> dragonS >> bonus;

		mpbonus[dragonS] += bonus;               // in case of dragons with same strenghts and different bonus 
		                                         // map to get the total bonus of Dragons with same strength
		st.insert(dragonS);                      // Set to avoid dragons with same strength
	}

	set<int>::iterator it;                       // Special pointer to traverse the Set

	for (it = st.begin(); it != st.end(); it++)
	{
		if (heroStrength > *it)
		{
			next = true;
			heroStrength += mpbonus[*it];
		}

		else 
		{
			next = false;
			break;
		}
	}
	if (next)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}