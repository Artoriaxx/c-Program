#include<iostream>
#include<cstring>
using namespace std;
long long a[105][105],b[105][105],c[100000],w[100000],f[100000],z[100000],cl[100000],wl[100000];
int main()//数组的大小要注意，后面的额cl，wl，f要开超过10^5因为100^2*7(n*m*k) 
{
	long long n,m,ti,A;
	cin>>n>>m>>ti>>A;
	long long v=min(ti,A-1);
	long long sumn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];//注意一开始要用二维数组存而不能直接输入处理 
		}                //因为要判断桃子数和采摘次数不同时为0的情况 
	}                    //若不同时为0，此时也是不符合的 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
		}
	};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=0&&b[i][j]!=0)//不同时为0，则将数据存入 
			{
				sumn++;//记录有多少合法的 
				c[sumn]=a[i][j];
				w[sumn]=2*(i+j);//花费注意来回，所以要乘2 
				z[sumn]=b[i][j];
			}
		}
	}
//	cout<<sumn;
	long long count=0;
//	int u=0;
//	for(int i=1;i<=sumn;i++)
//	{
//		u+=z[i]*c[i];
//	}
	for(int i=1;i<=sumn;i++)//拆解背包 
	{
		for(int j=1;j<=z[i];j<<=1)
		{
			count++;
			cl[count]=j*c[i];
			wl[count]=j*w[i];
			z[i]-=j;
		}
		if(z[i]>0)
		{
			count++;
			cl[count]=z[i]*c[i];
			wl[count]=z[i]*w[i];
		}
	}
//	for(int i=1;i<count;i++)
//	cout<<cl[i]<<" "<<wl[i]<<endl;
    f[0]=0;
	for(int i=1;i<=count;i++)
	{
		for(int j=v;j>=wl[i];j--)
		{
			f[j]=max(f[j],f[j-wl[i]]+cl[i]);//拆解完后是01背包 
		}
	}
	cout<<f[v];
	return 0;
}
