#include <iostream>
#include <string>

using namespace std;

int main()
{
	int operations_num,i,X = 0;
	string operation;
//*******************************

	cin >> operations_num;
	for (i = 0; i < operations_num; i++)
	{
		cin >> operation;
		if (operation.find("++") != -1)
			X++;
		else if (operation.find("--") != -1)
			X--;
	}
	cout << X;
	return 0;
}