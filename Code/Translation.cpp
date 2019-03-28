#include <iostream>
#include <string>

using namespace std;

int main()
{
	string Ber_word, Bir_word;
	int i, j;
//***********************************
	cin >> Ber_word >> Bir_word;

	for (i = 0, j = Ber_word.length() - 1; i < Ber_word.length(); i++, j--)
	{
		if (Ber_word[i] != Bir_word[j])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}