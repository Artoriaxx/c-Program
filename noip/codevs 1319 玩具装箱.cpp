//��̬ת�Ʒ��̣�f[i]=f[j]+(s[i]-s[j]-1-L��^2
//��k=s[i]-L-1,����f[i]=f[j]+k^2-2ks[j]+s[j]^2;
//��y=f[j]+s[j]^2,x=s[j],z=f[i]-k^2����y=2kx+z 
//��f[i]��С�� ��z��С 
//���ʽ���У�y��x����j�йصĳ�����z��δ֪�ģ���x��y�й�
//ö�ٵ�iʱ����һϵ�еĵ㣬����ÿ���㣬��һ��б��Ϊk��ֱ�ߣ���y�ύ�㼴Ϊz
//����Ҫ��z����Сֵ���������z��С�ĵ�һ����͹����
//�õ�������ά��һ��͹�����ڶ�β�ĵ㲻����͹��ʱ�����Ƴ�
//�������������ۣ�1.j<k'����slope(j,k')<2*k����k'��j��
//                2.j<k<l����slope(j,k)>slope(k,l)����k���Ա���ȥ
//                  (��Ϊά������һ����͹���� 
#include<iostream>
#include<cstring>
using namespace std;
long long c[50050],f[50050],s[50050];
int deq[50050];
double slope(int i,int j)
{
	return (1.0*(f[i]+s[i]*s[i]-f[j]-s[j]*s[j])/(s[i]-s[j]));//��б�ʺ��� 
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
		long long k=s[i]-L-1;//��ǰ���б�� 
		while(l<r&&slope(deq[l+1],deq[l])<=2*k)//�����ŵĵ� 
		l++;
		int j=deq[l];//�����ҵ������ŵ�� 
		f[i]=f[j]+(k-s[j])*(k-s[j]);
		while(l<r&&slope(deq[r],deq[r-1])>=slope(i,deq[r]))//�Ѳ�����͹���ĵ��Ƴ����� 
		r--;
		deq[++r]=i;//��������㣬ע��++r������r++ 
	}
	cout<<f[n];
	return 0;
}
