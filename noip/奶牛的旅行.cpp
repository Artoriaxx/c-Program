#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define inf 100000000
using namespace std;
int a[400],b[400];
double map[400][400];
double m[400],p;
char d;
double ans;
double s(int x,int y)
{
	return sqrt((a[y]-a[x])*(a[y]-a[x])+(b[y]-b[x])*(b[y]-b[x]));
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		cin>>d;
		if(d=='1')
		    map[i][j]=s(i,j);
		else
		    map[i][j]=inf;
		}
	}
	for(int k=1;k<=n;k++)
	    for(int i=1;i<=n;i++)
	        for(int j=1;j<=n;j++)
	        {
	        	if(k!=i && k!=j && i!=j && map[i][k] != inf && map[k][j] != inf && map[i][j] > map[i][k]+map[k][j])
	        	    map[i][j] = map[i][k]+map[k][j];
	        }
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	if(map[i][j] != inf && map[i][j] > m[i])
	    	    m[i]=map[i][j];
	    }
	ans=inf;
    for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	if(map[i][j] == inf && i!=j )
	    	{
	    		p=s(i,j);
	    	if(ans > m[i]+m[j]+p)
	    	{
	    		ans = m[i]+m[j]+p; 
	    	}
	    	}
	    }
	for(int i=1;i<=n;i++)
	{
		if(m[i]>ans)
		   ans=m[i];
	}
	printf("%.6lf",ans);
	return 0;
}
