#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string mathy;
	vector<char>vec;
	int i;

	cin >> mathy;
	for (i = 0; i < mathy.length(); i++)
	{
		if (mathy[i] != '+')
			vec.push_back(mathy[i]);
	}
	mathy.clear();
	sort(vec.begin(),vec.end());
	for (i = 0; i < vec.size(); i++)
	{
		mathy += vec[i];
		mathy += '+';
	}
	if (mathy[mathy.length() - 1] == '+')
		mathy.erase(mathy.length() - 1);

	cout << mathy;
	return 0;
}