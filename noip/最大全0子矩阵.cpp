#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
using namespace std;
int a[maxn][maxn];
int h[maxn],l[maxn],r[maxn],s[maxn];
int main()
{
	int n,s1=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
	    {
	    	cin>>a[i][j];
	    }
	}
	memset(h,0,sizeof(h));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{   
		    l[j]=r[j]=j;
			if(a[i][j]==0)
			{
				h[j]=h[j]+1;//悬线法，计算该点往上找有多少为0的点 
			}
			else
			{
				h[j]=0;//若该点为0，则使它为0 
			}
			while(l[j]-1>=1&&h[j]<=h[l[j]-1])//枚举左边界 
			{
				l[j]=l[l[j]-1];
			}
		}
		for(int j=n;j>=1;j--)//注意求右边界的范围时需要从j=n开始枚举，每次-- 
		{
            while(r[j]+1<=n&&h[j]<=h[r[j]+1])
			{
				r[j]=r[r[j]+1];
			}
			s[j]=h[j]*(r[j]-l[j]+1);
			if(s[j]>s1)
			s1=s[j];//找到一个最大的面积 
		}
	}
	cout<<s1;
	return 0;
}
