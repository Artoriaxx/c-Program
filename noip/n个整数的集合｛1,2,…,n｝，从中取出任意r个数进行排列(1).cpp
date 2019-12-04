#include<iostream>
using namespace std;
int s[101],a[101]={0};
int long long sum=0;
int n,r;
void print()
{
	for(int i=1;i<=r;i++)
	cout<<s[i]<<" ";
	cout<<endl;
	sum++;
}
void dfs(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(!(a[j]))
		{
			s[i]=j;
			a[j]=1;
			if(i<r) dfs(i+1);
			else print();
			a[j]=0;
		}
	}
}
int main()
{
	cin>>n>>r;
	dfs(1);
	cout<<sum<<endl;
	return 0;
}
