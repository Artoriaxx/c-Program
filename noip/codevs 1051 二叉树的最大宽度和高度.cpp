#include<iostream>
using namespace std;
int l[20],r[20],dep,bre[2000];
void dfs(int w,int deep)
{
	if(deep>dep) dep=deep;
	bre[deep]++;//ͳ��ÿһ����ȵĿ�� 
	if(l[w]) dfs(l[w],deep+1);//���±�����ͳ����� 
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
