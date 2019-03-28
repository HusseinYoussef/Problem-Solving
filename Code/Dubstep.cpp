#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string remix;
	string s = "WUB";
	int ipos,oldpos;
//*********************************************
	cin >> remix;
	oldpos = -2;
	while (true)
	{   
		ipos = remix.find(s);

		if (ipos == -1)
			break;                                       // i = -1 ---> means "WUB" not found
		if (ipos == oldpos)                              // So mission Done now OUT.
			remix.erase(ipos, s.length());               // Removing "WUB" if old & new position are the same.
		else if( ipos != oldpos && ipos != 0)
			remix.replace(ipos, s.length(), " ");        // Replacing WUB with space " "  if the new pos != the old
		oldpos = ipos;                                   // which means ---> a (jump) happend **No Need to Put space 
	}                                                    // in the Beginning.
	
	cout << remix;
	return 0;
}