#include<iostream>
#include<cstring>
#define maxn 6050
using namespace std;
int f[maxn][2],a[maxn];
struct Edge
{
	int next,to;
}edge [maxn*2];//������ͼ�����鿪2�� 
int num,head[maxn];
void addedge(int from,int to)
{
	edge[++num].next=head[from];//��һ���� 
	edge[num].to=to;//�ñߵ���ĵ� 
	head[from]=num;//��¼�õ㵽�ı� 
}
int vis[maxn];
void dfs(int v)
{
	if(vis[v]) return;
	vis[v]=true;
	f[v][1]=a[v];
	while(head[v]!=0)//�������㻹�б� 
	{
		if(!vis[edge[head[v]].to])//f[v][0]����ýڵ㲻ѡʱ��ֵ 
		{                         //f[v][1]����ýڵ�ѡʱ��ֵ 
			dfs(edge[head[v]].to);//����������������һ���� 
			f[v][0]+=max(f[edge[head[v]].to][0],f[edge[head[v]].to][1]);
			f[v][1]+=f[edge[head[v]].to][0];
		}
		head[v]=edge[head[v]].next;
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(head,0,sizeof(head));
		memset(vis,false,sizeof(vis));
		num=0;
		for(int i=1;i<=n;i++)
	    {
		    cin>>a[i];
	    }
	    int x,y;
	    while(cin>>x>>y)
	    { 
		    if(x==0&&y==0) break;
		    addedge(x,y);
		    addedge(y,x);
	    }
	    dfs(1);//����Ҹ��㵱��dfs 
	    cout<<max(f[1][0],f[1][1])<<endl;
	}
	return 0;
} 
