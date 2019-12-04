#include<iostream>
using namespace std;
double dp[450][450];int a[100005],cnt[100005];
int main()
{
	int n,m,b;
	cin>>n>>m;
	int count = 0;
	for(int i=1;i<=m;i++)
	{
		cin>>b;
		if(cnt[b] == 0)
		a[++count] = b;
		cnt[b]++;
	}
//	for(int i=1;i<=m;i++)
//	{
//		cout<<a[i]<<endl;
//	}
	dp[1][0]=1.0000;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i-1;j++)
		{
			for(int k=1;k<=count;k++)
			{
				dp[i][j]+=1/double(m)*double(cnt[a[k]])*dp[i-1][(j-(a[k])%i+i)%i];
			}
		}
	}
	for(int i=0;i<n-1;i++)
	{
		printf("%.8lf ",dp[n][i]);
	}
	printf("%.8lf\n",dp[n][n-1]);
	return 0;
}

