#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
using namespace std;
int a[maxn][maxn];
int h[maxn],l[maxn],r[maxn],s[maxn];
int main()
{
	int n,s1=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
	    {
	    	cin>>a[i][j];
	    }
	}
	memset(h,0,sizeof(h));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{   
		    l[j]=r[j]=j;
			if(a[i][j]==0)
			{
				h[j]=h[j]+1;//���߷�������õ��������ж���Ϊ0�ĵ� 
			}
			else
			{
				h[j]=0;//���õ�Ϊ0����ʹ��Ϊ0 
			}
			while(l[j]-1>=1&&h[j]<=h[l[j]-1])//ö����߽� 
			{
				l[j]=l[l[j]-1];
			}
		}
		for(int j=n;j>=1;j--)//ע�����ұ߽�ķ�Χʱ��Ҫ��j=n��ʼö�٣�ÿ��-- 
		{
            while(r[j]+1<=n&&h[j]<=h[r[j]+1])
			{
				r[j]=r[r[j]+1];
			}
			s[j]=h[j]*(r[j]-l[j]+1);
			if(s[j]>s1)
			s1=s[j];//�ҵ�һ��������� 
		}
	}
	cout<<s1;
	return 0;
}
