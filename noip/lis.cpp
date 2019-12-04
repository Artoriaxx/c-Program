#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10010
#define INF 0x3f3f3f3f
using namespace std;
int d[N],a[N],f[N];
int n,m,cnt,j;
inline int find(int x)
{
int l = 1, r = cnt, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (d[mid] < x) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
inline bool judge(int len)
{
	memset(f,0,sizeof(f));
	memset(d,INF,sizeof(d));
	cnt = 1;
	f[1] = 1;
	d[1] = a[1];
	int ans = 1;
	for (int i = 2;i <= n; i++)
	{
		j = find(a[i]) + 1;
		f[i] = j;
		if(f[i]>len)
		{
			for(int y = 1; y <= cnt; y++) d[y] = INF;
			f[i] = 1;
			d[1] = a[i];
			ans++;
			continue; 
		}
		d[j] = min(d[j], a[i]);
		if (f[i] > cnt) cnt = f[i];
	}
	return ans <= m;
}

int main()
{
	int T;
	/*
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	*/
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
		int l = 1, r = n, ans = 0;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			if(judge(m)) ans = m, r = m - 1;
			else l = m + 1;
		}
		cout << ans;
	}
	return 0;
}
