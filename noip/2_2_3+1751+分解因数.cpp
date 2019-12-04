//http://noi.openjudge.cn/ch0202/1751/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int dfs(int k,int i)
{
	int t=sqrt(k+0.5);
	int ans=1;//当找不到任何因子的时候应该返回1而不是0 
	for(int j=i;j<=t;j++)
		if(k%j==0) ans+=dfs(k/j,j);
	return ans;
}
int main()
{
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		printf("%d\n",dfs(k,2));
	}
	return 0;
}
