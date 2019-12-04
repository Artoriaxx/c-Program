//动态转移方程：f[i]=f[j]+(s[i]-s[j]-1-L）^2
//令k=s[i]-L-1,化简：f[i]=f[j]+k^2-2ks[j]+s[j]^2;
//令y=f[j]+s[j]^2,x=s[j],z=f[i]-k^2，则y=2kx+z 
//求f[i]最小， 即z最小 
//这个式子中，y和x是与j有关的常量，z是未知的，与x，y有关
//枚举到i时就有一系列的点，对于每个点，做一条斜率为k的直线，与y轴交点即为z
//我们要找z的最小值，则这个令z最小的点一定在凸包上
//用单调队列维护一个凸包，在队尾的点不满足凸包时将它移除
//所以有两个结论：1.j<k'，若slope(j,k')<2*k，则k'比j优
//                2.j<k<l，若slope(j,k)>slope(k,l)，则k可以被舍去
//                  (因为维护的是一个下凸包） 
#include<iostream>
#include<cstring>
using namespace std;
long long c[50050],f[50050],s[50050];
int deq[50050];
double slope(int i,int j)
{
	return (1.0*(f[i]+s[i]*s[i]-f[j]-s[j]*s[j])/(s[i]-s[j]));//求斜率函数 
}
int main()
{
	memset(f,0,sizeof(f));
	memset(deq,0,sizeof(deq));
	int n,L;
	cin>>n>>L;
	c[0]=0;s[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		c[i]+=c[i-1];s[i]=c[i]+i;
	}
	f[0]=0;deq[0]=0;
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		long long k=s[i]-L-1;//当前点的斜率 
		while(l<r&&slope(deq[l+1],deq[l])<=2*k)//找最优的点 
		l++;
		int j=deq[l];//接在找到的最优点后 
		f[i]=f[j]+(k-s[j])*(k-s[j]);
		while(l<r&&slope(deq[r],deq[r-1])>=slope(i,deq[r]))//把不满足凸包的点移除队列 
		r--;
		deq[++r]=i;//加入这个点，注意++r而不是r++ 
	}
	cout<<f[n];
	return 0;
}
