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

void addedge(int from,int to,int w)//�ڽӱ�ӱ� 
{
	edge[++num].next = head[from];
	edge[num].to = to;
	edge[num].w = w;
	head[from] = num;
}
int f[maxn],d[maxn],g[maxn],v[maxn];//f[i]��¼�ӽڵ㵽i�ڵ����Զ����,g[i]Ϊ��Զ���� 
//d[i]��i�ڵ����Զ����, v[]�Ƿ������� 

void dfs1(int u,int fa)//dfs��ǰ�ڵ�͸��ڵ� 
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int to = edge[i].to;
		if(to == fa) continue;//�����ٴη��ʸ��ڵ� 
		dfs1(to,u);//�ȱ������еĵ� 
		if(v[to] == 0)
		{
			v[to] = 1;//�ѷ��ʸõ� 
			if(f[to]+edge[i].w >= f[u])//����������ֵ����������ֵ�ʹδ�ֵ 
			{
				g[u] = f[u];
				f[u] = f[to]+edge[i].w;
			}
			else if(f[to]+edge[i].w > g[u])//���ֻ���ڴδ�ֵ����ֻ���´δ�ֵ 
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
			//���ֵ���ܴ���һ���ڵ�ת�ƣ�Ҳ���ܲ���
			//��������һ���ڵ�ת�������� f[to]+edge[i].w == f[u] ���ܴ����ֵת��
			//��Ϊ����ͬһ��·����������� 
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
