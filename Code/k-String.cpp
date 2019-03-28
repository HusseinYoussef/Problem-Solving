#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	int k, i;
	string input,rearranged_out;
	map<char, int>mp;
	set<char>st;
//************************

	cin >> k >> input;

	for (i = 0; i < input.length(); i++)
	{
		mp[input[i]]++;                                // Calculating how many each char appeared 
		st.insert(input[i]);                           // putting each char in a set
	}

	for (i = 0; i < input.length(); i++)
	{
		if (mp[input[i]] % k != 0)                     // every char must appear at least K times or Multiples of K
		{                                              // to find a solution
			cout << "-1";
			return 0;
		}	
	}

	set<char>::iterator it;

	for (it = st.begin(); it != st.end(); it++)
	{ 
		for(i=0;i<mp[*it] / k;i++)                     // Division to have specific number of Char in each segment
		rearranged_out += *it;
	}

	for (i = 0; i < k; i++)
		cout << rearranged_out;

	return 0;
}