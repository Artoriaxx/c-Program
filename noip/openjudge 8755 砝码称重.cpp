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
	int sumn=0;//����Ҫ������ȷ�������ע��ϸ�ڣ��� 
	for(int i=1;i<=6;i++)
	{
		cin>>a[i];
		k=a[i];
		sumn+=a[i]*b[i];
		for(int j=1;j<=k;j<<=1)//�����ر�������01���� 
	    {
	    	v[count++]=j*b[i];
	    	k-=j;
	    }
//	    cout<<k<<endl;
	    if(k>0)
	    {
	    	v[count++]=k*b[i];//���绹û���꣬�ٽ�ʣ��Ĳ�һ�� 
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
			f[j]=max(f[j],f[j-v[i]]);//������Щ����װ�� 
		}
	}
	int sum=0;
	for(int i=1;i<=sumn;i++)
	{
		if(f[i]!=0)
		{
			sum++;//ͳ��װ�������� 
		}
	}
	cout<<"Total="<<sum;
}
