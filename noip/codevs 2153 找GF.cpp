#include<iostream>
#include<cstring>
using namespace std;
int rmb[105],rp[105],timen[105],f[105][105],g[105][105];//����������time����Ϳ�������ֳ�ͻ�� 
int main()//f�����¼��һ����rmb��rp׷��Ů��������g�����¼��һ����rmb��rp������ʱ�� 
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
				if(f[j-rmb[i]][k-rp[i]]+1==f[j][k])//�����ж���ȵ�ʱ��ʱ��Ƚϳ�һ����Сʱ�� 
				    g[j][k]=min(g[j][k],g[j-rmb[i]][k-rp[i]]+timen[i]);
		    }
		}
	}
	int vis=0;//��¼׷����Ů���������ֵ 
	int ans=0x3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=r;j++)
		{
			if(f[i][j]<vis) continue;//��������ֵС����û�����壬�����´�ѭ�� 
			if(f[i][j]>vis)
			{
				vis=f[i][j];
				ans=0x3f3f3f3f;//������ҵ������ֵ����ô֮ǰ����Сʱ����Ч�����±Ƚ� 
			}
			ans=min(ans,g[i][j]);
		}
	}
	cout<<ans;
	return 0;
}
