#include<iostream>
#include<ctime>
using namespace std;
struct matrix
{
	long long a11,a12,a21,a22;
	matrix(long long x,long long y,long long a,long long b)//构造函数 
	{
		a11=x;
		a12=y;
		a21=a;
		a22=b;
	}
};
matrix matrixmul(matrix x,matrix y)
{
	matrix c=matrix(1,0,0,1);//单位矩阵 
	c.a11=x.a11*y.a11+x.a12*y.a21;
	c.a12=x.a11*y.a12+x.a12*y.a22;
	c.a21=x.a21*y.a11+x.a22*y.a21;
	c.a22=x.a21*y.a12+x.a22*y.a22;
	return c;
};
matrix fast_pow(matrix a, long long n)
{
	matrix ans=matrix(1,0,0,1);
	for(;n;n>>=1,a=matrixmul(a,a))
	{
		if(n&1)
		    ans=matrixmul(ans,a);
	}
	return ans;
};
int main()
{
	long long n=9223372036854775800;
	clock_t begin,end;
	begin=clock();
//	for(int i=1;i<n;i++)
//	{
//	    n=n*10;
//	}
	matrix d=matrix(0,1,1,1);
//	long long f1=1,f2=1,t;

//	matrix a=matrix(0,1,1,1);
//	matrix b=matrix(1,0,0,1);
//	matrix c=matrixmul(a,b);
//	cout<<c.a11<<" "<<c.a12<<endl;
//	cout<<c.a21<<" "<<c.a22<<endl;
    int i=10000;
    while(i--)
    {
    	d=fast_pow(d,n);
    }
	
//	for(int i=3;i<=n;i++)
//	{
//		t=f1+f2;
//		f1=f2;
//		f2=t;
//	}
	end=clock();
	cout<<double(end-begin)/CLOCKS_PER_SEC<<endl;
	return 0;
}
