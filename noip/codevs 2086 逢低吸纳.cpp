#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
long long a[5500],f[5500],g[5500][110];
long long ans[110];
long long maxn;
void plus1(long long *x,long long *y)//�߾��ȼӷ���ע��ָ�� 
{
	int len=1;int t=0;int z[110]={0}; 
	while(len<=x[0]||len<=y[0])
	{
		z[len]=x[len]+y[len]+t;//t�洢��λ ��x��y����ÿλ��Ӽ��Ͻ�λ 
		t=z[len]/10;
		z[len]%=10;//ʹÿλ������0~9 
		len++;//���ֳ���+1 
	}
	z[len]=t;
	if(!z[len])
	len--;//ȥ�������0 
	x[0]=len;
	for(int i=1;i<=len;i++)
	{
		x[i]=z[i];//��z����Ľ������x���� 
	} 
} 
int main()
{
	memset(f,0,sizeof(f));
	memset(ans,0,sizeof(ans));//ans���ڸ߾��ȱ�����飬ע����� 
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<1<<" "<<1;//��n==1����ֱ����� 
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[i][0]=0;
		g[i][1]=0;//���g���飬��������Ϊ�߾���g�Ƕ�ά
	}
	f[1]=1;g[1][0]=1;g[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=maxn)
		{
			maxn=a[i];
			g[i][0]=1;
			g[i][1]=1;//0������λ�� 
		}
		for(int j=1;j<=i-1;j++)
		{
			if(a[i]<a[j]&&f[i]<f[j])
			{
				f[i]=f[j];
			}
		}
		f[i]++;//��½�������ģ�� 
		set<long long> vis;//Ҫд��int�� 
		for(int j=i-1;j>=1;j--)//����ѭ���������ҵ����ķ����� 
		{
			if(f[j]+1==f[i]&&vis.find(a[j])==vis.end()&&a[i]<a[j])//ʹ��set�������� 
			{
			    vis.insert(a[j]);
			    plus1(g[i],g[j]);//���潫��ͬ��������� 
			}
		}
	}
	int maxl=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>=maxl)
		maxl=f[i];
//        cout<<f[i]<<" ";
//        cout<<q[i]<<" "<<endl;
	}
	set<long long> vis1;
    for(int i=n+1;i>=1;--i)//Ҫ����ѭ������Ϊ��ǰ�濪ʼ�Ҳ����ҵ���෽�� 
    {
    	if(vis1.find(a[i])==vis1.end()&&f[i]==maxl)
    	{
    		vis1.insert(a[i]);
    		plus1(ans,g[i]);
		}
	}
	cout<<maxl<<" ";
	for(int i=ans[0];i>=1;i--)//��ӡ�߾��ȣ��赹�Ŵ�ӡ 
	    cout<<ans[i];
}
