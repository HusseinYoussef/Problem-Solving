#include <iostream>
#include <string>

using namespace std;

int main()
{  int i;
	string first_num,sec_num;
	
	cin>> first_num >> sec_num;

	int* p = new int[first_num.length()];

	for(i=0;i<first_num.length();i++)
	{
	   if(first_num[i] != sec_num[i])
		   p[i] = 1;
	   else
		   p[i] = 0;
	}
   
	for(i=0;i<first_num.length();i++)
	cout << p[i];

delete []p;
return 0;
}