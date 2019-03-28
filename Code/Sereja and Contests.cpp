#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int x_currentRound, rounds_done, i, count = 0;
	int round_type, identifier;
	map<int, bool>participated;
	vector<int>vec;
//*********************************

	cin >> x_currentRound >> rounds_done;

	for (i = 0; i < rounds_done; i++)
	{
		cin >> round_type;
		if (round_type == 1)
		{
			cin >> identifier;
			participated[identifier] = 1;         // Rounds  which took part in will be 1 (identifier appeared)
			cin >> identifier;                    // missed ones' identifiers will not appear ( = 0)
			participated[identifier] = 1;
		}
		else
		{
			cin >> identifier;
			participated[identifier] = 1;
		}
	}
	for (i = 1; i < x_currentRound; i++)
	{
		if (participated[i] != 1)
			vec.push_back(i);                      // vector to store the missed identifiers 
	}
	sort(vec.begin(), vec.end());          
	
	if(vec.size() != 0)
	for (i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i + 1] - vec[i] == 1)                // if the difference =1 then every 2 elements represent 1 Div2 
		{
			count++;
			i++;
		}
	}
	cout << count + (vec.size() - count * 2) << " " << vec.size();
	return 0;
}
