#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	string profile_name;
	int i;
	set<char>st;
//****************************
	cin >> profile_name;

	for (i = 0; i < profile_name.length(); i++)
	{
		st.insert(profile_name[i]);               // set to remove Duplicates
	}

	if (st.size() % 2 != 0)
		cout << "IGNORE HIM!";
	else
		cout << "CHAT WITH HER!";

	return 0;
}