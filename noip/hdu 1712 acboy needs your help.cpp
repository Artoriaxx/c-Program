#include<iostream>
#include<cstring>
using namespace std;
int a[105][105],f[105];
int main()
{
    int n,m;
    
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        else
        {
            memset(f,0,sizeof(f));
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    cin>>a[i][j];
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int v=m;v>=0;v--)
                {
                    for(int k=1;k<=m;k++)
                    {
                    	if(v-k>=0)
                        f[v]=max(f[v],f[v-k]+a[i][k]);
                    }
                }
            }
            cout<<f[m]<<endl;
        }
    }
    return 0;
}
