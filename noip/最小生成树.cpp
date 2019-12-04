
#include<algorithm>
using namespace std;


struct Edge
{
	int a,b,c;
}edge[];

bool cmp(Edge x,Edge y)
{
	if(x.c<y.c)
		return true;
	else
		return false;
}


sort(edge+1,edge+m+1,cmp);

int i;

for(i=1;i<=m;i++)
{
	int x=getf(a[i]);
	int y=getf(b[i]);
	if(x!=y)
		fa[x]=y; 
}

















 
