#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 100000
using namespace std;
int a[maxn+5],g[maxn+5],f[maxn+5];//g数组记录以上升为结尾的最大抖动长度，f则记录下降的~ 
int main()
{
	int n;
	cin>>n;
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	f[1]=1;g[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])//最后一个是上升 
		{
			f[i]=f[i-1];//记录以下降为结尾的最长抖动数列的数组数值等于前一个 
			g[i]=max(f[i-1]+1,g[i-1]);//可以新加入一个长度   什么时候可以从g[i-1]转移？ 好像可以去掉并不影响答案 
		}
		if(a[i]==a[i-1])
		{
			f[i]=f[i-1];
			g[i]=g[i-1];
		}
		if(a[i]<a[i-1])
		{
			f[i]=max(g[i-1]+1,f[i-1]);
			g[i]=g[i-1];
		}
	}
	int ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(g[i]>ans||f[i]>ans)
//		    ans=max(f[i],g[i]);
//	}
	cout<<max(f[n],g[n]);//其实最后一个中必定含有最大值，因为f和g数组都是统计到当前最长的 
	return 0;
}
