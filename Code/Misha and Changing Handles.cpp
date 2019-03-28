#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{  
	int Request_num,i;
	string person, handle,s;
	map<string, string>mp;
	map<string, int>mycheckmp;
	vector<string>real_persons;
//******************************

	cin >> Request_num;
	
	for (i = 0; i < Request_num; i++)
	{
		cin >> person >> handle;
		
		if (mycheckmp[person] == 0 && mycheckmp[handle] == 0)           // when mycheck[person] = 0 this means that is a new user
		{                                                               // putting only new users in a vector
			mp[person] = handle;                                        // assign the handle to the user 
			real_persons.push_back(person);                             // if the handle isnt used before
			mycheckmp[handle] = 1;
		}

		else if (mycheckmp[person] == 1 && mycheckmp[handle] == 0)
		{
			mp[person] = handle;                                        // if the user appeared before
			mycheckmp[handle] = 1;                                      // this means it is the new handle of and old User
		}
	}

	cout << real_persons.size() << endl;

	for (i = 0; i < real_persons.size(); i++)                           // Looping the vector to get the real user and his
	{                                                                   // latest handle
		s = mp[real_persons[i]];
		while(mp.count(s))
		{
			s = mp[s];
		}
		cout << real_persons[i] << " " << s << endl;
	}
	return 0;
}