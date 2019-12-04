#include<iostream>
#include<cstring>
using namespace std;
int ci[150],gi[150],f[150][150];
int main()
{
	int n,t;
	while(cin>>n>>t)
	{
		memset(f,0,sizeof(f));
		int m,s;
		for(int i=1;i<=n;i++)
		{
			cin>>m>>s;
			for(int j=1;j<=m;j++)
			{
				cin>>ci[j]>>gi[j];
			}
		    if(s==1)
		    {
			    for(int j=0;j<=t;j++)
				    f[i][j]=f[i-1][j];
		    	for(int k=1;k<=m;k++)
			    {
				    for(int v=t;v>=ci[k];v--)
				    {
					    f[i][v]=max(f[i][v],f[i-1][v-ci[k]]+gi[k]);//如果最多选一件，那么要么不选，即f[i-1][v] 
				    }                                              //要么选1件，从f[i-1]组中转移，不能从本组转移 
			    }
			}
			else if(s==2)
			{
				for(int j=0;j<=t;j++)
				    f[i][j]=f[i-1][j];
			    for(int k=1;k<=m;k++)
				{
					for(int v=t;v>=ci[k];v--)
					{
					    f[i][v]=max(f[i][v],f[i][v-ci[k]]+gi[k]);//如果可以任意选，则在本组中每一件选或不选 
					}                                            //在当前i中修改 
				}
		    }
			else if(s==0)
			{
				for(int u=0;u<=t;u++)
					f[i][u]=-0x3f3f3f3f;
//如果这里赋值为-1，那么后面的转移就要先判断是不是从值为-1转移，如果是的话则不能转移。
//而且对于这样需两次比较，那么比较的顺序需要注意
//那么下面的代码应该这样写： 
			// for(int k=1;k<=m;k++)
			//{
				//for(int v=t;v>=ci[k];v--)
					//{
						//if(f[i][v-ci[k]!=-1) f[i][v]=max(f[i][v],f[i][v-ci[k]]+gi[k]);
						//if(f[i-1][v-ci[k]!=-1]) f[i][v]=max(f[i][v],f[i-1][v-ci[k]]+gi[k]);
			
					//}
			//}
//这两句话的顺序是不能交换的
//因为ci[k]可能为0，如果交换的话，那么f[i][v]的值就已经被改变了，就会改变两次，从而导致错误
//而这种顺序下，先改变f[i][v]的值，对于下一次比较，使用的是f[i-1][],所以不会有影响 
				for(int k=1;k<=m;k++)
				{
					for(int v=t;v>=ci[k];v--)
					{
						f[i][v]=max(f[i][v],max(f[i][v-ci[k]]+gi[k],f[i-1][v-ci[k]]+gi[k]));
					}
				}
//f[i][j]: 是不选择当前工作；
//f[i-1][v-ci[k]]+gi[k]: 第一次在本组中选物品，由于开始将该组dp赋为了负无穷，
//所以第一次取时，必须由上一组的结果推知，这样才能保证得到全局最优解；
//f[i][v-ci[k]]+gi[k]：表示选择当前工作，并且不是第一次取;
//赋值为-inf的好处是，不用考虑比较的次数，直接转移
//因为题目数据不大，如果是错误的转移是不会大于0的，也就是最优的 
			}
		}
		cout<<max(f[n][t],-1)<<endl;
	}
	return 0;
}
