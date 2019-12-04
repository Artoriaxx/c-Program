//状态转移方程：
//f[i,j]=max{f[i,k-1]*f[k+1,j]+a[k]}  (i<k<j)。
//初始：
//f[i,i]=a[i];  f[i,j]=1;
//目标：f[1,n]
#include<iostream>
using namespace std;
int root[35][35];//root[i][j]表示区间i到j之间的根 
long long f[35][35],a[35];
void visit(int i,int j)//输出i到j区间的先序遍历 
{
	if(i<=j)
	{
		cout<<root[i][j]<<" ";
		visit(i,root[i][j]-1);
		visit(root[i][j]+1,j);//递归寻找 
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n+1;i++)//从0开始枚举，动态转移方程中出现了0 
	{
		for(int j=0;j<=n+1;j++)//考虑1个区间内端点可能为根节点，此时 
		{                      //分数应该为左/右子树*1+本身分数，所以把f赋值为1 
			f[i][j]=1;
		}
	}
		for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=a[i];//叶子节点的赋值为本身分数 
		root[i][i]=i;//一个节点的根节点为自己 
	}
	for(int l=1;l<=n-1;l++)//最外层循环枚举区间长度 
	{
		for(int i=1;i<=n-l;i++)//枚举起点 
		{
			int j=i+l;//起点加长度为终点 
			for(int k=i;k<=j;k++)//枚举中间点 
			{
				if(f[i][j]<f[i][k-1]*f[k+1][j]+a[k])
				{
					f[i][j]=f[i][k-1]*f[k+1][j]+a[k];//找一个区间内最大的加分 
					root[i][j]=k;//这一区间内的根 
				}
			}
		}
	}
	cout<<f[1][n]<<endl;
	visit(1,n);
	return 0;
}
