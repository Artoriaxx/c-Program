#include<cstdio>
int n,m,p;
int map[][];
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	}
	for(i=n;i>=1;i--)
	{
		for(j=m;j>=1;j--)
			map[i][j]=map[i][j]+map[i-1][j-1]-map[i][j-1]-map[i-1][j];
	}
	scanf("%d",&p);
	while(p--)
	{
		int a,b,c,d,x;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&x);
		map[a][b]+=x;
		map[a][d+1]-=x;
		map[c+1][b]-=x;
		map[c+1][d+1]+=x;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			map[i][j]=map[i][j]+map[i-1][j]+map[i][j-1]-map[i-1][j-1];
	}
}
