#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#define maxn 35000
using namespace std;
int dist[maxn],d[maxn],anc[maxn][16],a[maxn];
	int n,u,v,m;
struct egde
{
	int next,to;
}edge[maxn*2];
int head[maxn],num_edge;//head�����¼���ǵ����ܵ���ĵ�һ���� 
void add_edge(int from,int to)
{
	edge[++num_edge].next=head[from];//��¼���ܵ������һ���� 
	edge[num_edge].to=to;//��¼�ñ����ܵ���ĵ� 
	head[from]=num_edge;//��¼���������ܴﵽ�ĵ�һ���� 
}
void dfs(int u)
{
	for(int i=head[u];i!=0;i=edge[i].next)
	{
		int f[maxn]={0};
		int to=edge[i].to;
		if(f[to]==0)
		{
		    f[to]=1;
		    if(to==anc[u][0]) continue;
		    d[to]=d[u]+1;
		    dist[to]=dist[u]+1;
		    anc[to][0]=u;
		    dfs(to);
		}
	}
}
void init()
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			anc[i][j]=anc[anc[i][j-1]][j-1];
		}
	}
}
int lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	int f=d[b]-d[a];
	for(int i=0;1<<i<=f;i++)
	{
		if((1<<i)&f) b=anc[b][i];
	}
	if(a!=b)
	{
		for(int i=(int)log2(n);i>=0;i--)
		{
			if(anc[a][i]!=anc[b][i])
			{
				a=anc[a][i];b=anc[b][i];
			}
		}
		a=anc[a][0];
	}
	return a;
}
int main()
{
	num_edge=0; 
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
    }
    memset(a,0,sizeof(a));
    scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
    }
	dfs(1);
    init();
    for(int i=1;i<=m;i++)
    if(a[i+1]!=0)
    {
        ans+=d[a[i]]+d[a[i+1]]-2*d[lca(a[i],a[i+1])];
    }
    cout<<ans;
}
