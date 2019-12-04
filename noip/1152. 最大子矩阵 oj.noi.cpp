#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[305][305],sum[305][305],f[305],b[305];//b数组记录被压缩后 
int main()
{
	int n, m;
	cin>>n>>m;
	memset(sum,0,sizeof(sum));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j] == 0) a[i][j] = -0x3f3f3f3f;
			sum[i][j]=sum[i][j-1]+a[i][j];//求每一行的和 
//			cout<<sum[i][j]<<" ";
        }
	}
	int l,r,ans=-100000000;
	for(r=1;r<=m;r++)
	{
		for(l=r;l>=1;l--)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=sum[i][r]-sum[i][l-1];//将n列压缩至1列 
			}
			for(int i=1;i<=n;i++)
			{
				f[i]=max(f[i-1]+b[i],b[i]);//在被压缩后的列中求最大子序列和 
				if(f[i]>ans)
				{
					ans=f[i];//统计最大的和 
				}
			}
		}
	}
	cout<<ans;
}
