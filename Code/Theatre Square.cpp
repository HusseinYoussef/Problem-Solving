#include <iostream>
#include <cmath>

using namespace std;

int main() 
{ 
	long long n,m,a,result;

	
	cin >> n >> m >>a;

	result = ceil( n / (double)a ) * ceil( m / (double)a);

	cout <<  result;


	return 0;
}