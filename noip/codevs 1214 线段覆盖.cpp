#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int a,b;
}x[120];
int cmp(node x,node y)
{
	return x.b<y.b;//���߶��Ҷ˵����� 
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].b;
		if(x[i].a>x[i].b) swap(x[i].a,x[i].b);//ʹ��˵�С���Ҷ˵� 
	}
	sort(x+1,x+n+1,cmp);
	int cnt=0,vis=-1000;
//	for(int i=1;i<=n;i++)
//	cout<<x[i].a<<" "<<x[i].b<<endl;
	for(int i=1;i<=n;i++)
	{
		if(x[i].a>=vis)//̰��������ж������߶β����� 
		{
		    cnt++;
		    vis=x[i].b;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
