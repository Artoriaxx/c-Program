#include<stdio.h>
#include<map>
#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1000000007
using namespace std;
int f[20005];
int a[2005][2005],flag[2005];
int cot[2005],n,t;
int findf(int now)
{
	if(f[now]==now)return now;else return f[now]=findf(f[now]);
}
void dfs(int now,int pre)
{
	flag[now]=1;
	while(cot[now]<n)
	{
		cot[now]++;
		if(a[now][cot[now]]==pre)
		{
			int b,c;
			b=findf(f[now]);c=findf(f[a[now][cot[now]]]);
			if(b!=c)
			{
				if(b>c)
				{
					f[b]=c;
				}else f[c]=b;
				printf("%d %d\n",now,pre);
			}
			flag[now]=0;
			return;
		}else
		if(!flag[a[now][cot[now]]])
		{
			dfs(a[now][cot[now]],now);
			if(a[now][cot[now]]==pre)
			{
				int b,c;
				b=findf(f[now]);c=findf(f[a[now][cot[now]]]);
				if(b!=c)
				{
					if(b>c)
					{
						f[b]=c;
					}else f[c]=b;
					printf("%d %d\n",now,pre);
				}
				flag[now]=0;
				return;
			}	
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=n;i++)cot[i]=1,flag[i]=0;
		for(int i=1;i<=n;i++)f[i]=i;
		dfs(1,0);
		printf("\n");
	}
	return 0;
}