#include<iostream>
using namespace std;
int l[20],r[20],dep,bre[2000];
void dfs(int w,int deep)
{
	if(deep>dep) dep=deep;
	bre[deep]++;//统计每一个深度的宽度 
	if(l[w]) dfs(l[w],deep+1);//向下遍历，统计深度 
	if(r[w]) dfs(r[w],deep+1);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	dfs(1,1);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,bre[i]);
	cout<<ans<<" "<<dep;
}
