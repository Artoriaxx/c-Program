#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int a,b,v;
}x[2000];
int cmp(node x,node y)
{
	return x.b<y.b;
}
int a[2000],f[2000];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].b>>x[i].v;
	}
	sort(x+1,x+n+1,cmp);
	f[1]=x[1].v;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(x[i].a>=x[j].b)
			f[i]=max(f[i],f[j]+x[i].v);//�����������߶β��ཻ�� 
			else//�ཻ                 //��ԭֵ��֮ǰ���ཻ�����ֵ+���߶εļ�ֵ�Ƚ� 
			f[i]=max(f[i],max(f[j],x[i].v));//ԭֵ��ѡ�����߶λ�ѡ���Ƚ� 
		}
	}
	cout<<f[n];
	return 0;
}
