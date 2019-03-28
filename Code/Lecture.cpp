#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n,m,i;
	map<string,string>mp;
	string first_language,sec_language;
   cin >> n >> m;
    for(i=0;i<m;i++)
	{  
	    cin >> first_language >> sec_language;

		mp[first_language]=sec_language;
		
	}

	for(i=0;i<n;i++)
	{
	  cin >> first_language;
	  if(first_language.length() == mp[first_language].length())
		  cout << first_language << " ";

	  else if(first_language.length() > mp[first_language].length())
		  cout << mp[first_language] << " ";

	  else
		  cout << first_language << " " ;  
	}
	return 0;
}