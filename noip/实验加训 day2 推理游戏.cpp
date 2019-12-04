#include<iostream>
#define maxn 20010
#define LL long long
#define p 998244353
using namespace std;
LL fac[maxn];LL ans;
int num[5][maxn][5],tot[5],vac,cur[5],cnt[5];
inline int fastpow(int a,int b)
{
	if(b<0) return 0;
	LL ans=1,base=a;
	while(b)
	{
		if(b&1) (ans*=base)%=p;
		(base*=base)%=p;
		b>>=1;
	}
	return ans;
}
inline int C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	LL ans=fac[n]*fastpow(fac[m],p-2)%p;
	(ans*=fastpow(fac[n-m],p-2))%=p;
	return ans;
}
void dfs(int now)
{
	if(tot[now]==0)
	{
		dfs(now+1);
		return;
	}
	if(now>=4)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=1;j<=tot[i];j++)
			{
				bool flag=false;
				for(int k=0;k<4;k++)
				{
					if(num[i][j][k]==cur[i])
					{
						cnt[k]++;
						flag=true;
						break;
					}
				}
				if(!flag)
				{
					for(int k=0;k<4;k++) cnt[k]=0;
					return;
				}
			}
		}	
		LL nowc=1,pre=0;
		for(int i=0;i<4;i++)
		{
			if(tot[i]>0)
			{
				(nowc*=C(tot[4]-pre,cur[i]-cnt[i]))%=p;
				pre+=cur[i]-cnt[i];
			}
		}
		(nowc*=fastpow(vac,tot[4]-pre))%=p;
		(ans+=nowc)%=p;
		for(int i=0;i<4;i++) cnt[i]=0;
		return;
	}
	for (int i=0;i<4;i++)
	{
		cur[now]=num[now][1][i];
		dfs(now+1);
		cur[now]=0;
	}
}
int main()
{
	int n,cat,cnt=0;
	cin>>n;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			tot[4]++;
		}
		else
		{
			char s[10];cin>>s;
			int x=s[0]-'A';
			tot[x]++;
			for(int j=0;j<4;j++)
			{
				cin>>num[x][tot[x]][j];
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		if(tot[i]==0) vac++;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
