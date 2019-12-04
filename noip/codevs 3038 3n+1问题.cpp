#include<iostream>
using namespace std;
int dfs(int i,int count)
{
	if(i==1) return count;
	if(i%2==1) 
		return dfs(3*i+1,++count);//×¢ÒâÊÇ++count 
	else 
		return dfs(i/2,++count);
}
int main()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q;
		cout<<dfs(q,0)<<endl;
	}
	return 0;
}
