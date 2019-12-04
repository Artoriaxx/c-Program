#include<iostream>
using namespace std;
int a[101];
int main()
{
	int b,n,rear=1,front=0;
    cin>>b>>n;
    a[1]=b;
    while(rear<n)
    {
    	rear++;
    	a[rear]=2*a[front+1]+1;
    	rear++;
    	a[rear]=3*a[front+1]+1;
    	front++;
    }
    for(int i=1;i<=n;i++)
        cout<<i<<";"<<a[i]<<endl;
    return 0;
}
