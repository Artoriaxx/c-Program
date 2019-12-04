/*
dp[i][j][0]:��ǰ�ڵ�i����j�λ��ᣬ�ӷ�������ߵ�i��
dp[i][j][1]:��ǰ�ڵ�i����j�λ��ᣬ��������ߵ�i��
ת�ƣ�dp[u][j+ci[u]][k]=max(dp[to][j][k])+a[u];(k=0||1,k=1ʱҪ��j!=0) 
*/ 
#include<iostream>
#include<cstring>
#define maxn 50050
using namespace std;
struct edge
{
	int to,next;
}edge[maxn*2];
int num,head[maxn];
int a[maxn],ci[maxn];
int dp[maxn][5][2];
int ans;
int n,c;
void adde(int from,int to)
{
	edge[++num].next=head[from];
	edge[num].to=to;
	head[from]=num;
}
void init()
{
	memset(edge,0,sizeof(edge));
	memset(head,0,sizeof(head));
	memset(dp,0,sizeof(dp));
	memset(ci,0,sizeof(ci));
	memset(a,0,sizeof(a));
	num=0;ans=0;
}
void dfs(int u,int fa)
{
	dp[u][ci[u]][0]=a[u];
	dp[u][ci[u]][1]=a[u];
	ans=max(ans,a[u]);//��ʱ����ans 
	for(int i=head[u];i;i=edge[i].next)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		dfs(to,u);
		for(int j=0;j<=c;j++)//���ֵ������Ϊ������ƴ��������ö������������Ĵ��� 
		{
			for(int k=0;k+j<=c;k++)
			{
				if(j!=c) ans=max(ans,dp[u][j][0]+dp[to][k][1]);
				if(k!=c) ans=max(ans,dp[u][j][1]+dp[to][k][0]);
				if(k+j<c) ans=max(ans,dp[u][j][0]+dp[to][k][0]);
				if(k+j==c) ans=max(ans,dp[u][j][1]+dp[to][k][1]);
			}
		}
		for(int j=0;j<=c;j++)
		{
			dp[u][j+ci[u]][0]=max(dp[u][j+ci[u]][0],dp[to][j][0]+a[u]);
			if(j)//�����ʣ������ſ����Ǵ������ת�ƣ���Ϊ����һ������Ͳ������� 
			{
				dp[u][j+ci[u]][1]=max(dp[u][j+ci[u]][1],dp[to][j][1]+a[u]);
			}
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		init();
		cin>>n>>c;
		for(int i=0;i<=n-1;i++)
		{
			cin>>a[i]>>ci[i];
		}
		int q,p;
		for(int i=0;i<=n-2;i++)
		{
			cin>>q>>p;
			adde(q,p);
			adde(p,q);
		}
		dfs(0,-1);
		cout<<ans<<endl;
	}
	return 0;
}
