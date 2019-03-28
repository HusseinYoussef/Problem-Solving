#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int foul_num, i;
	string home, away;
	int match_time, player_num;
	char team, card;
	map<int, bool>outH;      // Home players that got kiked out
	map<int, bool>outA;      // Away players that got kiked out       // 1-->> OUT
	map<int, char> crmph;    // cards that Home players receive
	map<int, char> crmpA;    // cards that away players receive	
//***********************************************
	cin >> home >> away >> foul_num;

	for (i = 0; i < foul_num; i++)
	{
		cin >> match_time >> team >> player_num >> card;
		if (team == 'h')
		{
			if ((card == crmph[player_num] && card == 'y' && outH[player_num] == 0) || (card == 'r' && outH[player_num] == 0))
			{
				cout << home << " " << player_num << " " << match_time << endl;
				outH[player_num] = 1;     // Player OUT
				
			}
			crmph[player_num] = card;
		}
		else if (team == 'a')
		{
			if ((card == crmpA[player_num] && card == 'y' && outA[player_num] == 0) || (card == 'r' && outA[player_num] == 0))
			{
				cout << away << " " << player_num << " " << match_time << endl;
				outA[player_num] = 1;     // Player OUT
				
			}
			crmpA[player_num] = card;
		}
	}
 	return 0;
}