#include<iostream>
#include<cstring>
using namespace std;
int v[1050],k;
int f[1050];
int b[7]={0,1,2,3,5,10,20};
int main()
{
	memset(f,0,sizeof(f));
	int a[7];
	int count=1;
	int sumn=0;//必须要把总重确切算出，注意细节！！ 
	for(int i=1;i<=6;i++)
	{
		cin>>a[i];
		k=a[i];
		sumn+=a[i]*b[i];
		for(int j=1;j<=k;j<<=1)//将多重背包拆解成01背包 
	    {
	    	v[count++]=j*b[i];
	    	k-=j;
	    }
//	    cout<<k<<endl;
	    if(k>0)
	    {
	    	v[count++]=k*b[i];//假如还没拆完，再将剩余的拆一次 
		}
	}
//	for(int i=1;i<=count;i++)
//	{
//			cout<<v[i]<<" ";
//	}

	f[0]=1;
	for(int i=1;i<=count;i++)
	{
		for(int j=sumn;j>=1;j--)
		{
			if(j-v[i]>=0)
			f[j]=max(f[j],f[j-v[i]]);//看看哪些可以装出 
		}
	}
	int sum=0;
	for(int i=1;i<=sumn;i++)
	{
		if(f[i]!=0)
		{
			sum++;//统计装出的数量 
		}
	}
	cout<<"Total="<<sum;
}
