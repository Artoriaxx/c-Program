#include<iostream>
#include<cstring>
using namespace std;
int rmb[105],rp[105],timen[105],f[105][105],g[105][105];//如果数组设成time好像和库里的名字冲突了 
int main()//f数组记录花一定的rmb和rp追的女孩个数，g数组记录花一定的rmb和rp所花的时间 
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>rmb[i]>>rp[i]>>timen[i];
	}
	int m,r;
	cin>>m>>r;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=rmb[i];j--)
		{
			for(int k=r;k>=rp[i];k--)
			{
				if(f[j-rmb[i]][k-rp[i]]+1>f[j][k])
				{
					f[j][k]=f[j-rmb[i]][k-rp[i]]+1;
					g[j][k]=g[j-rmb[i]][k-rp[i]]+timen[i];
				}
				if(f[j-rmb[i]][k-rp[i]]+1==f[j][k])//单独判断相等的时候，时间比较出一个较小时间 
				    g[j][k]=min(g[j][k],g[j-rmb[i]][k-rp[i]]+timen[i]);
		    }
		}
	}
	int vis=0;//记录追到的女孩个数最大值 
	int ans=0x3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=r;j++)
		{
			if(f[i][j]<vis) continue;//如果比最大值小，则没有意义，进入下次循环 
			if(f[i][j]>vis)
			{
				vis=f[i][j];
				ans=0x3f3f3f3f;//如果又找到了最大值，那么之前的最小时间无效，重新比较 
			}
			ans=min(ans,g[i][j]);
		}
	}
	cout<<ans;
	return 0;
}
