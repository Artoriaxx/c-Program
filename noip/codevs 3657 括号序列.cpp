#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int f[150][150],v[150][150];
char a[150];
int judge(int i,int j)
{
	if((a[i]=='('&&a[j]==')')||(a[i]=='['&&a[j]==']')) return 1;//判断端点所求区间端点序号是否匹配 
	else return 0;
}
int main()
{
	memset(f,0,sizeof(f));
	memset(v,0,sizeof(v));
	char b;int len=1;
	while(cin>>b)
	{
		a[len]=b;
		len++;
	}
	for(int i=1;i<=len-1;i++)
	{
		f[i][i]=1;//只有一个字符，则需修改1步 
	}
	for(int p=1;p<=len-1;p++)
	{
		for(int i=1;i<=len-p;i++)
		{
			int j=i+p;
			if(judge(i,j))
			{
				f[i][j]=f[i+1][j-1];//如果匹配则修改步数只需看区间内部 
			}
			else f[i][j]=0x3f3f3f3f;
			for(int k=i;k<=j;k++)
			{
				if(f[i][j]>f[i][k]+f[k+1][j])
				{
					f[i][j]=f[i][k]+f[k+1][j];//枚举中间点相加 
				}
			}
		}
	}
	cout<<f[1][len];
	return 0;
}
