#include <iostream>
#include <map>

using namespace std;
int main()
{
	int clients,i,card_num;
	long long couples_num = 0;
	map<int,long long>mp;                         
//**************************************
	cin >> clients;

	for (i = 0; i < clients; i++)
	{
		cin >> card_num;
		mp[card_num]++;                          // Map used to get how many each card number appeared
	}

	for (i = -10; i < 0; i++)
	{
    	couples_num += mp[i] * mp[-i];           // Combinations = how many each number appeared * how many each of 
 	}                                            // opposite number appeared ( 0 is an Exception)

	if (mp[0] > 1)                                           // 0 is a special case since there isno opposite for it
		couples_num += mp[0] * (mp[0] - 1)/2;                  // so the the number of combinations can be obtained using 
	                                                         // Combinations  (number of occurence C 2)
	if (clients == 1)
	couples_num = 0;

	cout << couples_num;
	return 0;
}
