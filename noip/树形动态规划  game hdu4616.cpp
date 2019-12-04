/*
树形动态规划  game hdu4616
《game》 http://acm.hdu.edu.cn/showproblem.php?pid=4616
测试数据不全面，有遗漏的情况，例如：
1
2 1
10 1
3 1
0 1
*/ 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define  N 50005
#define INF 99999999
using namespace  std;
struct Edge
{
    int e, next;
}edge[N*2+5];

int head[N], eNum;
int c[N], val[N], n, k, u,v,ans, dp[N][4][2];

void init()
{
    eNum = 0; ans = 0;
   	memset(head, -1, sizeof(head));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=k; j++)
        {
        	for(int m=0;m<=1;m++)
                dp[i][j][m]= -INF;
        }
    }
}

void AddEdge(int u, int v)
{
	eNum++;
    edge[eNum].e = v;
    edge[eNum].next = head[u];
    head[u] = eNum;
}

int max2(int x, int y)
{
    return x > y ? x : y;
}

void dfs(int u, int fa)
{
		
	if(c[u]) 
	{
		dp[u][0][0] =-INF;
		dp[u][0][1] =-INF;
		dp[u][1][0]=-INF;
		dp[u][1][1]=val[u];
	}
	else
	{
		dp[u][0][0]=val[u];
		dp[u][0][1]=-INF;
		dp[u][1][1]=-INF;
		dp[u][1][0]=val[u];
	}
	ans=max(ans,val[u]);
	
	 
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].e;
        if(v==fa) continue;
        dfs(v, u);
    	if(c[u]==0)
    	{
    		//dp[u][0][0] = max(dp[u][0][0],dp[v][0][0]+val[u]);//0-0
    		//dp[u][0][0]=max(dp[u][0][0],)//1-0
    		//dp[u][0][1] = max(dp[u][0][1],dp[v][0][1]+val[u]);
//    		ans=max(ans,dp[u][0][0]);
//    		ans=max(ans,dp[u][0][1]);
			for(int j=0; j<k; j++)//若在前一个分支用到所有机会，则后一个分支无法走到  
			{
				for(int w=0;j+w<=k;w++)
				{
					if(j+w==k) {
						if(dp[u][j][1]>-1&&dp[v][w][1]>-1) ans=max(ans,dp[u][j][1]+dp[v][w][1]);

						if(dp[u][j][0]>-1&&dp[v][w][1]>-1) ans=max(ans,dp[u][j][0]+dp[v][w][1]);

					}
					else
					{
						if(dp[u][j][1]>-1&&dp[v][w][1]>-1) ans=max(ans,dp[u][j][1]+dp[v][w][1]);
		
						if(dp[u][j][1]>-1&&dp[v][w][0]>-1) ans=max(ans,dp[u][j][1]+dp[v][w][0]);

						if(dp[u][j][0]>-1&&dp[v][w][1]>-1) ans=max(ans,dp[u][j][0]+dp[v][w][1]);

						if(dp[u][j][0]>-1&&dp[v][w][0]>-1) ans=max(ans,dp[u][j][0]+dp[v][w][0]);

					}
				}
			}
			if(dp[u][k][1]>-1&&dp[v][0][0]>-1) //当前一个分支用光所有机会，后一个分支就只能全是0 
			{
				ans=max(ans,dp[u][k][1]+dp[v][0][0]);
			}
    		for(int j=0; j<k; j++) 
      		{
      		
      			if(dp[v][j][0]>-1)
				  {
				  	dp[u][j][0]=max(dp[u][j][0],dp[v][j][0]+val[u]);
      				ans=max(ans,dp[u][j][0]);
				  } 
      			
      			if(dp[v][j][1]>-1)
				  {
				  	dp[u][j][1]=max(dp[u][j][1],dp[v][j][1]+val[u]);
				  	ans=max(ans,dp[u][j][1]);
				  } 
      			dp[u][j+1][0]=max(dp[u][j+1][0],dp[u][j][0]);
      			ans=max(ans,dp[u][j+1][0]);
      			dp[u][j+1][1]=max(dp[u][j+1][1],dp[u][j][1]);
			   	ans=max(ans,dp[u][j+1][1]);
			} 
			if(dp[v][k][1]>-1) {
				dp[u][k][1]=max(dp[u][k][1],dp[v][k][1]+val[u]);
				ans=max(ans,dp[u][k][1]);	
			}		    		 
      	}
      	else 
		{
			for(int j=0; j<=k; j++)//有可能在前一个分支用到所有机会 
			{
				for(int w=0;j+w<=k;w++)
				{
					if(j==k)
					{
						if(dp[u][j][1]>-1&&dp[v][w][0]>-1) max(ans,dp[u][j][1]+dp[v][w][0]);
						//if(ans==202) cout<<"u="<<u<<" j="<<j<<" [1] v="<<v<<" w="<<w<<endl;
					}
					else{
						if(j+w==k) {
							if(dp[u][j][0]>-1&&dp[v][w][1]>-1) ans=max(ans,dp[u][j][0]+dp[v][w][1]);
							
							if(dp[u][j][1]>-1&&dp[v][w][0]>-1) ans=max(ans,dp[u][j][1]+dp[v][w][0]);
							//if(ans==202) cout<<"u="<<u<<" j="<<j<<" [2] v="<<v<<" w="<<w<<endl;
							if(dp[u][j][1]>-1&&dp[v][w][1]>-1) ans=max(ans,dp[u][j][1]+dp[v][w][1]);
	
						}
						else
						{
							if(dp[u][j][1]>-1&&dp[v][w][1]>-1) ans=max(ans,dp[u][j][1]+dp[v][w][1]);
							
							if(dp[u][j][1]>-1&&dp[v][w][0]>-1) ans=max(ans,dp[u][j][1]+dp[v][w][0]);
						
							if(dp[u][j][0]>-1&&dp[v][w][1]>-1) ans=max(ans,dp[u][j][0]+dp[v][w][1]);
						
							if(dp[u][j][0]>-1&&dp[v][w][0]>-1) ans=max(ans,dp[u][j][0]+dp[v][w][0]);

						}
					}	
				}
			}
      		for(int j=0; j<k; j++) 
      		{
			   	 	if(dp[v][j][0]>-1)
						{
							dp[u][j+1][0]=max(dp[u][j+1][0],dp[v][j][0]+val[u]);
							ans=max(ans,dp[u][j+1][0]);		
						} 
			   	 	if(dp[v][j][1]>-1) 
						{
							dp[u][j+1][1]=max(dp[u][j+1][1],dp[v][j][1]+val[u]);
							ans=max(ans,dp[u][j+1][1]);
						}
			   	 	dp[u][j+1][1]=max(dp[u][j+1][1],dp[u][j][1]);
			   	 	ans=max(ans,dp[u][j+1][1]);
			   	 	dp[u][j+1][0]=max(dp[u][j+1][0],dp[u][j][0]);
			   	 	ans=max(ans,dp[u][j+1][0]);
			}    		
      	}
    }
}

int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        init();
        for(int i=0; i<n; i++)
            scanf("%d%d",&val[i],&c[i]);
        
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d",&u,&v);
            AddEdge(u, v);
            AddEdge(v, u);
        }
        
         dfs(0,-1);	
        cout<<ans<<endl;
//	for(int i=0;i<3;i++)
//		for(int j=0;j<2;j++)
//			for(int k=0;k<2;k++)
//				cout<<"d["<<i<<"]["<<j<<"]["<<k<<"]="<<dp[i][j][k]<<endl;
    }

    return 0;
}
/*
可用测试数据
8

10 3
1 0
1 1
2 1
3 1
9 1
5 0
6 0
7 0
8 0
4 0
0 1
0 2
0 3
1 5
1 4
2 6
2 7
3 8
3 9

4 1
10 1
1 0
2 0
3 0
0 1
0 2
0 3

7 3
1 1
5 1
6 1
50 0
100 0
40 0
5 0
0 1
0 2
1 3
2 4
3 5
4 6

3 1
23 0
12 0
123 1
0 2
2 1

3 2
23 0
12 0
123 1
0 2
2 1

2 1
10 1
3 1
0 1

3 1
1 1
3 1
5 1
0 1
0 2

1 1
1 1 
*/ 
