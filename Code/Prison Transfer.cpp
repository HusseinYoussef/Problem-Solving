#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int prisoners_num, i,crime_level, transfered_prisoners;
	int chosen_prisoners=0,count=0,x;
	vector<int>vec;
//*******************************************************
	cin >> prisoners_num >> crime_level >> transfered_prisoners;

	for (i = 0; i < prisoners_num; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	                                 /**** Avoid Nested Loops (Time Limit Exceed) ****/	
	i = 0;
	while(i<prisoners_num)
	{
		if (vec[i] <= crime_level)
			count++;
		else
			count = 0;                               // making the counter zero in case of a number bigger than vec[i]
		

		if (count == transfered_prisoners)
		{
			chosen_prisoners++;
			count = transfered_prisoners - 1;           // just pretending going back and increasing the counter              
		}
		i++; 
	}

	cout << chosen_prisoners << endl;
	return 0;
}