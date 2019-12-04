#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int f[4050][4050];//记录a串到i,b串到j为止需要修改的最短长度 
int main()
{
	memset(f,0,sizeof(f));
	string a,b;
	cin>>a>>b;
	for(int i=1;i<=a.length();i++)
	f[i][0]=i;
	for(int i=1;i<=b.length();i++)
	f[0][i]=i;
	for(int i=1;i<=a.length();i++)
	{
		for(int j=1;j<=b.length();j++)
		{
			if(a[i-1]==b[j-1])
			{
				f[i][j]=f[i-1][j-1];
			}
			if(a[i-1]!=b[j-1])
			{
				f[i][j]=min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+1);
			}
		}
	}
	cout<<f[a.length()][b.length()];
	return 0； 
} 
