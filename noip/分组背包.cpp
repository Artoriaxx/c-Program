







struct Info
{
	int v,t,a;
}xu[];

int n,m;

bool cmp(Info x,Info y)
{
	return (x.a<y.a);
	/*
	if(x.a<y.a)
		return true;
	else
		return false;
	*/
}

int dp[][],cc;

int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",xu[i].v,xu[i].t,xu[i].a);
	sort(xu+1,xu+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		int s=i;
		while(i<n && xu[i].a && xu[i+1].a)
			i++;
		cc++;
		for(j=0;j<=m;j++)
		{
			dp[cc][j]=dp[cc-1][j];
			for(k=s;k<=i;k++)
			{
				if(j-xu[k].t>=0)
					dp[cc][j]=max(dp[cc][j],dp[cc-1][j-xu[k].t]+xu[k].v);
			}
		}
	}
}














