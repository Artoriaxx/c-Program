#include<iostream>
#include<cstring>
using namespace std;
long long a[3050],b[3050],f[3050][3050]//f[i][j]记录以b[j]为结尾的最长上升公共子序列;
int main()
{
	memset(f,0,sizeof(f));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int maxn;
	for(int i=1;i<=n;i++)
	{
		maxn=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j])//相等的话，则接到之前最长上升公共子序列之后，加上自己 
			{
				f[i][j]=maxn+1;
			}
			if(a[i]!=b[j])//若不等，则a[i]对最长上升子序列无影响，由前一个a[i]转移 
			{
				f[i][j]=f[i-1][j];
			}
			if(a[i]>b[j]&&f[i][j]>maxn)//考虑假如a[i]==b[j]时，b[j]要接到最长的序列后，                           
			{                          //且要满足b[j]>b[k](1<=k<=j-1),用maxn记录，使之n^2复杂度 
				maxn=f[i][j];
			}
		}
	}
	maxn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]>maxn)
			maxn=f[i][j];
		}
//		for(int j=1;j<=n;j++)
//		{
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
	}
	cout<<maxn;
	return 0;
}
