#include<iostream>
#include<cstring>
using namespace std;
int a[600],b[600];
void plus1(int *a,int *b)//高精度加法 
{
	int i=1,x=0,c[600]={0};
	while(i<=a[0]||i<=b[0])
	{
		c[i]=a[i]+b[i]+x;
		x=c[i]/10;
		c[i]%=10;
		i++;
	}
	c[i]=x;
	while(!c[i]) i--;
	a[0]=i;
	for(int j=1;j<=i;j++)
	{
		a[j]=c[j];
	}
}
void minus1(int *a,int *b)
{
	int i=1,c[600]={0};
	while(i<=a[0]||i<=b[0])
	{
		if(a[i]<b[i])
		{
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
		i++;
	}
	while(!c[i]) i--;
	a[0]=i;
	for(int j=1;j<=a[0];j++)
	{
		a[j]=c[j];
	}
}
void multiply(int *a,int *b)
{
	int c[600]={0};
	for(int i=1;i<=a[0];i++)
	{
		int x=0;
		for(int j=1;j<=b[0];j++)
		{
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+b[0]]=x;
	}
	int len=a[0]+b[0];
	while(!c[len]) len--;
	a[0]=len;
	for(int j=1;j<=a[0];j++)
	{
		a[j]=c[j];
	}
}
int main()
{
	string n,m,u;
	cin>>n>>m;
//	if(n.length()<m.length()||(n.length()==m.length()&&n<m))
//	{
//		swap(n,m);
//		cout<<"-";
//	}//减法预处理 
	a[0]=n.length();b[0]=m.length();
	for(int i=1;i<=n.length();i++)
	{
		a[i]=n[a[0]-i]-'0';
	}
	for(int i=1;i<=m.length();i++)
	{
		b[i]=m[b[0]-i]-'0';
	}
//	minus1(a,b);
//	plus1(a,b);
    plus1(a,b);
	for(int i=a[0];i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
