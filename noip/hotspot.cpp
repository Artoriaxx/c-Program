#include<iostream>
#include<set>
#include<algorithm>
#define maxn 200010
using namespace std;
set<int> s[maxn];
struct point
{
	int rec;int hot;
}p[maxn];
void addedge(int u,int v)
{
	s[u].insert(v);
	s[v].insert(u); 
}
void deledge(int u,int v)
{
	s[u].erase(s[u].find(v));
	s[v].erase(s[v].find(u));
}
inline void hotspot(int x)
{
	p[x].hot++;
}
inline void connect(int x,int y)
{
	addedge(x,y);
	p[x].rec-=p[y].hot;
	p[y].rec-=p[x].hot;
}
inline void disconnect(int x,int y)
{
	deledge(x,y);
	p[x].rec+=p[y].hot;
	p[y].rec+=p[x].hot;
}
int main()
{
	int n,m;
	cin>>n>>m;
	char s1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>s1;
		if(s1=='S')
		{
			cin>>x;
			hotspot(x);
		}
		if(s1=='L')
		{
			cin>>x>>y;
			connect(x,y);
		}
		if(s1=='D')
		{
			cin>>x>>y;
			disconnect(x,y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(set<int>::iterator it=s[i].begin();it!=s[i].end();it++)
		{
			p[i].rec+=p[*it].hot;
		}
	}
	for(int i=1;i<n;i++)
	{
		cout<<p[i].rec<<" ";
	}
	cout<<p[n].rec<<endl;
	return 0;
}
