//http://noi.openjudge.cn/topic/19920/
#include<iostream>
#include<cstdio>
using namespace std;
int dfs(int m, int n,int k)//m��ƻ������n�����ӣ���һ�����k��ƻ�� 
{
	int ans=0;
	if(m<0) return 0;//���ƻ������0��˵���˷���ͨ���жϷ��� 
	if(n==0) 
	{
		if(m==0)return 1;//���ƻ�������Ӷ�����0��˵���˷����ԣ�����һ�ַ��� 
		else return 0; //�������û�ˣ�����ƻ����û���꣬˵���˷����� 
	}
	for(int i=k;i<=m;i++)//ÿһ�㶼��С��ǰһ��ŵ�ƻ���� 
		{
			ans+=dfs(m-i,n-1,i);
		}
	
	return ans;
}
int main()
{
	int m,n,t,ans=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>m>>n;
		ans=dfs(m,n,0);//��һ�����ӿ��Դ�0��ƻ������ 
		cout<<ans<<endl;	
	}
	
	return 0;
}
