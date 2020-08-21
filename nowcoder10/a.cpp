#include<cstdio>
#include<cmath>
inline int phi(int n)
{
    int zc=n,all=sqrt(n);
    for(int i=2;i<=all;i++)
	{
		if(n%i!=0)continue;
    	zc=zc/i*(i-1);
    	while(n%i==0)n/=i;
    }
    if(n>1)zc=zc/n*(n-1);
    return zc;
}
inline int pow(int x,const int y,const int mod)
{
	int res=1;
	for(int i=1;i<=y;i<<=1,x=(long long)x*x%mod)if(i&y)res=(long long)res*x%mod;
	return res;
}
int q[100001];
inline int G(const int m)
{
	const int PHI=phi(m);
	q[0]=0;
	const int limit=sqrt(PHI);int zc=PHI;
	for(int i=2;i<=limit;i++)
		if(zc%i==0)
		{
			q[++q[0]]=PHI/i;
			while(zc%i==0)zc/=i;
		}
	if(zc>1)zc=q[++q[0]]=PHI/zc;
	for(int g=2;;g++)
	{
		bool fla=1;
		if(pow(g,PHI,m)!=1)continue;
		for(int i=1;i<=q[0];i++)
			if(pow(g,q[i],m)==1)
			{
				fla=0;
				break;
			}
		if(fla)return g;
	}
}
int m,g;
const int  N = 1e6 + 50;
int a[N];
int main()
{
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d",&m);
        g=G(m);
        int now=1;
        printf("%d", now);
        a[now] = 1;
        for(int i=1;i<=m-2;i++){
            if (i & 1) now = now * 2 % m;
            else now = now * 3 % m;
            if (a[now] == 1) puts("======");
            else printf(" %d", now);
        }
        puts("");
        printf("%d\n", g);
        
    }
	
    return 0;
}