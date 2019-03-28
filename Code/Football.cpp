#include <iostream>
#include <string>
using namespace std;

int main()
{
	string positions;

//**********************
	cin >> positions;

	if (positions.find("0000000") != -1 || positions.find("1111111") != -1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}