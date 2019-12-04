#include<iostream>
//#include<cstring>
#define maxn 200010
using namespace std;
int pos[maxn],vis[maxn],a[maxn],ans=0x7f7f7f7f;
void dfs(int now,int k)
{
	pos[now] = k;
	vis[now] = 1;
	if(vis[a[now]] == 0)
	dfs(a[now],k + 1);
	if(vis[a[now]] == 1 && pos[a[now]] != 0)
	ans = min(ans,pos[now] - pos[a[now]] + 1);
	pos[now] = 0;
}
int main(){
	int n;
	freopen("123.in","r",stdin);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i]) 
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}
