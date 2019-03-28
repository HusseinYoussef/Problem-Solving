#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int rounds_num, i, score,max_score = 0;
	string name;
	map<string, int>mp;
	int scores[1001];
	string names[1001];
//*****************************************************

	cin >> rounds_num;
	for (i = 1; i <= rounds_num; i++)
	{
		cin >> name >> score;
		mp[name] += score;           // Map to store the last scores for each player
		names[i-1] = name;           // array of players
		scores[i-1] = mp[name];      // array of scores for each of each player at certain round
	}
	map<string, int>::iterator it;

	for (it = mp.begin(); it != mp.end(); it++)
 	{                                                          
		if (it->second > max_score)                    // Travesing the map to find the maximum score
			max_score = it->second;
	}
	for (i = 0; i < rounds_num; i++)
	{
		if (scores[i] >= max_score && mp[names[i]] == max_score)     // Traversing the array and see if the score at certain
		{                                                          // round is >= maximum score and this player has the max score at the end
			cout << names[i];
			return 0;
		}
	}
}