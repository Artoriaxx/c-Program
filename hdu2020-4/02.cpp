#include <bits/stdc++.h>
using namespace std;
const int NN=2010;
int a[NN],d[NN];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        double ans=0;int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d",a+i,d+i);
        for(int i=1;i<=n;i++){
            double res=0;
            long long diej=ceil(100.0 / a[i]) * d[i];
            for(int j=1;j<=n;j++){
                long long diei=ceil(100.0 / a[j]) * d[j];
                
                if(diei>diej)res+=1;
                else if(diei==diej)res+=0.5;
            }
            ans=max(ans,res);
        }
        printf("%.10lf",ans/n);
    }
    return 0;
}