#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n,m,i,x;
	int arr[100100];
	int ans[100100];
	set <int> st;
//*************************************
	cin >> n >> m;

	for(i=0;i<n;i++)
		cin >> arr[i];

	for(i=n-1;i >=0 ; i--)                      // Starting from the end to the wanted element
	{
	      st.insert(arr[i]);                    // Updating the set each time
		                                        // and storing the size in ans
	   ans[i] = st.size();                      // Getting all answers
	}

	for(i=0;i<m;i++)
	{
	   cin >> x;
	   cout << ans[x-1] << endl;
	}
	return 0;
}