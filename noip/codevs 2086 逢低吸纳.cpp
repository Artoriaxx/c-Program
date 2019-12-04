#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
long long a[5500],f[5500],g[5500][110];
long long ans[110];
long long maxn;
void plus1(long long *x,long long *y)//高精度加法，注意指针 
{
	int len=1;int t=0;int z[110]={0}; 
	while(len<=x[0]||len<=y[0])
	{
		z[len]=x[len]+y[len]+t;//t存储进位 ，x与y数组每位相加加上进位 
		t=z[len]/10;
		z[len]%=10;//使每位数字在0~9 
		len++;//数字长度+1 
	}
	z[len]=t;
	if(!z[len])
	len--;//去掉多余的0 
	x[0]=len;
	for(int i=1;i<=len;i++)
	{
		x[i]=z[i];//将z数组的结果赋给x数组 
	} 
} 
int main()
{
	memset(f,0,sizeof(f));
	memset(ans,0,sizeof(ans));//ans由于高精度变成数组，注意清空 
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<1<<" "<<1;//若n==1，则直接输出 
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[i][0]=0;
		g[i][1]=0;//清空g数组，别忘了因为高精度g是二维
	}
	f[1]=1;g[1][0]=1;g[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=maxn)
		{
			maxn=a[i];
			g[i][0]=1;
			g[i][1]=1;//0用来存位数 
		}
		for(int j=1;j<=i-1;j++)
		{
			if(a[i]<a[j]&&f[i]<f[j])
			{
				f[i]=f[j];
			}
		}
		f[i]++;//最长下降子序列模板 
		set<long long> vis;//要写在int内 
		for(int j=i-1;j>=1;j--)//倒序循环，才能找到最大的方案数 
		{
			if(f[j]+1==f[i]&&vis.find(a[j])==vis.end()&&a[i]<a[j])//使用set进行判重 
			{
			    vis.insert(a[j]);
			    plus1(g[i],g[j]);//动规将不同方案数相加 
			}
		}
	}
	int maxl=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>=maxl)
		maxl=f[i];
//        cout<<f[i]<<" ";
//        cout<<q[i]<<" "<<endl;
	}
	set<long long> vis1;
    for(int i=n+1;i>=1;--i)//要倒着循环，因为从前面开始找不是找到最多方案 
    {
    	if(vis1.find(a[i])==vis1.end()&&f[i]==maxl)
    	{
    		vis1.insert(a[i]);
    		plus1(ans,g[i]);
		}
	}
	cout<<maxl<<" ";
	for(int i=ans[0];i>=1;i--)//打印高精度，需倒着打印 
	    cout<<ans[i];
}
