#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
	string input,temp("");
	set<string>st;
//*********************************************
	cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		st.insert(input);

		temp = input[input.size() - 1];
		temp += input.substr(0, input.size() - 1);
		input = temp;
	}
	cout << st.size();
	return 0;
}