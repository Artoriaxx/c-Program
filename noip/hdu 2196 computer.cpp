#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 10050
using namespace std;
struct edge
{
	int from,to,w,next;
}edge[maxn*2];

int num,head[maxn*2];

void addedge(int from,int to,int w)//邻接表加边 
{
	edge[++num].next = head[from];
	edge[num].to = to;
	edge[num].w = w;
	head[from] = num;
}
int f[maxn],d[maxn],g[maxn],v[maxn];//f[i]记录子节点到i节点的最远距离,g[i]为次远距离 
//d[i]是i节点的最远距离, v[]是访问数组 

void dfs1(int u,int fa)//dfs当前节点和父节点 
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int to = edge[i].to;
		if(to == fa) continue;//不能再次访问父节点 
		dfs1(to,u);//先遍历所有的点 
		if(v[to] == 0)
		{
			v[to] = 1;//已访问该点 
			if(f[to]+edge[i].w >= f[u])//如果大于最大值，则更新最大值和次大值 
			{
				g[u] = f[u];
				f[u] = f[to]+edge[i].w;
			}
			else if(f[to]+edge[i].w > g[u])//如果只大于次大值，则只更新次大值 
			{
				g[u] = f[to]+edge[i].w;
			}
		}
	}
}

int v1[maxn];

void dfs2(int u,int fa)
{
	for(int i = head[u]; i ;i = edge[i].next)
	{
		int to = edge[i].to;
		if(to == fa) continue;
		if(v1[to] == 0)
		{
			d[to] = max(d[u],f[to]+edge[i].w == f[u] ? g[u] : f[u])+edge[i].w;
			//最大值可能从上一个节点转移，也可能不从
			//当不从上一个节点转移且满足 f[to]+edge[i].w == f[u] 则不能从最大值转移
			//因为这样同一条路径会计算两次 
			v1[to] = 1;
		}
		dfs2(to,u);
	}
}

void init()
{
	memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    memset(edge,0,sizeof(edge));
    memset(d,0,sizeof(d));
    memset(head,0,sizeof(head));
    memset(v,0,sizeof(v));
    memset(v1,0,sizeof(v1));
    num=0;
}

int main()
{
	int n,a,wi;
	while(cin>>n)
	{
		init();
		for(int i=2;i<=n;i++)
		{
			cin>>a>>wi;
			addedge(i,a,wi);
			addedge(a,i,wi);
		}
		dfs1(1,-1);
		d[1]=0;
		dfs2(1,-1);
		for(int i=1;i<=n;i++)
		cout<<max(f[i],d[i])<<endl;
	}
	return 0;
}
