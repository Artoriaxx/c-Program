//http://noi.openjudge.cn/topic/19920/
#include<iostream>
#include<cstdio>
using namespace std;
int dfs(int m, int n,int k)//m个苹果，第n个盘子，上一层放了k个苹果 
{
	int ans=0;
	if(m<0) return 0;//如果苹果少于0，说明此法不通，中断返回 
	if(n==0) 
	{
		if(m==0)return 1;//如果苹果和盘子都等于0，说明此法可以，返回一种方法 
		else return 0; //如果盘子没了，但是苹果还没放完，说明此法不行 
	}
	for(int i=k;i<=m;i++)//每一层都不小于前一层放的苹果数 
		{
			ans+=dfs(m-i,n-1,i);
		}
	
	return ans;
}
int main()
{
	int m,n,t,ans=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>m>>n;
		ans=dfs(m,n,0);//第一个盘子可以从0个苹果放起 
		cout<<ans<<endl;	
	}
	
	return 0;
}
