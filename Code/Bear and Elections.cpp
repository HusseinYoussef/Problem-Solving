#include <iostream>

using namespace std;
void sorting(int*,int);
int main()
{
    int n,i,x,result=0;  bool exit=true;
    cin>>n;
    int* A=new int[n-1];
    cin>>x;
    for(i=0;i<n-1;i++)
    cin>>A[i];
    sorting(A,n-1);
    while(exit)
       {
        if(x>A[n-1])
        {
        exit=false;
        cout<<result;
        }
        else
        {
            A[n-1]--;
            x++;
            result++;
            sorting(A,n-1);
        }
        }
    return 0;
}
void sorting(int* A,int size)
{
    int temp;
    for(int i=0;i<size;i++)
        {
        if(A[i]>A[i+1])
            {
                temp=A[i];
                A[i]=A[i+1];
                A[i+1]=temp;
            }
        else
            continue;
            }
}

