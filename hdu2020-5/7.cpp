#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
long long n,k;
const long long NN=200100;
struct pp{
    long long to,v;
};
vector<pp>con[NN];
long long nums[NN],numfa[NN];
long long deg[NN];
void dfs1(long long cur,long long fa){
    long long up=con[cur].size();
    nums[cur]=0;
    for(long long i=0;i<up;i++){
        pp nex=con[cur][i];
        if(nex.to!=fa){
            dfs1(nex.to,cur);
            if(deg[nex.to]<=k){
                nums[cur]+=nex.v+nums[nex.to];
            }
        }
    }
}
void dfs2(long long cur,long long fa,long long vv){
    long long up=con[cur].size();
    if(fa==-1){
        numfa[cur]=0;
    }
    else if(fa>=1){
        if(deg[fa]<=k){
            if(deg[cur]<=k)numfa[cur]=numfa[fa]+nums[fa]-nums[cur];
            else numfa[cur]=numfa[fa]+vv+nums[fa];
        }
        else numfa[cur]=0;
    }
    for(long long i=0;i<up;i++){
        pp nex=con[cur][i];
        if(nex.to!=fa){
            dfs2(nex.to,cur,nex.v);
        }
    }
}
int main(){
    long long t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        for(long long i=1;i<=n;i++)con[i].clear();
        for(long long i=1;i<=n;i++)deg[i]=nums[i]=numfa[i]=0;
        for(long long i=1;i<n;i++){
            long long x,y,z;
            scanf("%lld%lld%lld",&x,&y,&z);
            pp neww;
            neww.to=x;neww.v=z;
            con[y].push_back(neww);
            neww.to=y;
            con[x].push_back(neww);
            deg[x]++;
            deg[y]++;
        }
        dfs1(1,-1);
        dfs2(1,-1,-1);
        long long maxn=0;
        //printf("%lld\n",numfa[2]);
        for(long long i=1;i<=n;i++){
            maxn=max(maxn,nums[i]+numfa[i]);
        }
        printf("%lld\n",maxn);
    }
    return 0;
}