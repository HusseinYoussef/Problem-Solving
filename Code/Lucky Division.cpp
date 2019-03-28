#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string input;
	int i,x;
	set<char>st;
//*********************
	cin >> input;
	stringstream ss;
	ss << input;
	ss >> x;
	
	for (i = 0; i < input.length(); i++)
	{
		st.insert(input[i]);
	}

	if (st.size() == 2 && input.find('4') != -1 && input.find('7') != -1)
		cout << "YES";
	else if (st.size() == 1 && (input.find('4') != -1 || input.find('7') != -1))
		cout << "YES";
	else if (x % 4 == 0 || x % 7 == 0 || x % 44 == 0 || x % 77 == 0 || x % 47 == 0 || x % 74 == 0  || x %  444 == 0 || x % 777 == 0 || x % 447 == 0 || x % 477 == 0 || x % 744 == 0  || x % 774 == 0)
		cout << "YES";
	else
	cout << "NO";
	return 0;
}