#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{ 
	long long a,b,steps;
	unsigned long long s;

	cin >> a >> b >> s;
	steps = abs(a) + abs(b);                                  // minimum steps to reach the distination

if(s >= abs(a) + abs(b))
{
	if(s % 2 == 0 && (s-steps) % 2 ==0)                       // 3shan tkon "yes" lazm el $steps tkon >= (a+b)
		cout << "Yes";                                        // w el fr2 ben el $steps w el (a+b) lazm ykon even
	else if(s % 2 != 0 && (s-steps) % 2 ==0)                  // even 3shan step forward and step backward
		cout << "Yes";
	else 
		cout << "No";
}

else
   cout << "No";

return 0;
}