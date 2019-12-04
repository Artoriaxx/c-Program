#include<iostream>
#include<cstring>
#include<set>
#define p 1000000007
using namespace std;
long long a[300050], f[300050], g[300050];
long long ans = 0;
long long maxn;
int main()
{
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	f[1] = 1, g[1] = 1;
	maxn = a[1];
	for(int i = 2; i <= n; i++)
	{
		if(a[i] >= maxn)
		{
			maxn = a[i];
			g[i] = 1;
		}
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= i - 1; j++)
		{
			if(a[i] < a[j] && f[i] < f[j])
			{
				f[i] = f[j];
			}
		}
		f[i]++;
		set<long long> vis;
		for(int j = i - 1; j >= 1; j--)
		{
			if(f[j] + 1 == f[i] && vis.find(a[j]) == vis.end() && f[i] && a[i] < a[j])
			{
			    vis.insert(a[j]);
			    (g[i] += g[j]) %= p;
			}
		}
	}
	int maxl = 0;
	for(int i = 1; i <= n; i++)
	{
		if(f[i] >= maxl)
		maxl = f[i];
//        cout<<f[i]<<" ";
//        cout<<q[i]<<" "<<endl;
	}
	set<long long> vis;
    for(int i = 1; i <= n; i++)
    {
    	if(vis.find(a[i]) == vis.end() && f[i] == maxl)
    	{
    		vis.insert(a[i]);
    		(ans += g[i]) %= p;
		}
	}
	cout<<maxl<<" "<<ans;
	return 0;
}
