#include <iostream>
#include <string>

using namespace std;

int main()
{
	string instruction;
//***********************
	cin >> instruction;

	if (instruction.find('H') != -1 || instruction.find('9') != -1 || instruction.find('Q') != -1)
		cout << "YES";
	else if (instruction.find('+') != -1 && (instruction.find('H') != -1 || instruction.find('9') != -1 || instruction.find('Q') != -1))
		cout << "YES";                      // '+' should be with one of the language letter to increment "HQ9"
	else
		cout << "NO";

	return 0;
}