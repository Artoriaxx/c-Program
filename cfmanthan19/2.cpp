#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int NN=100100;
const int oo=1e9+10;
char ss[NN];
int s[NN];
int y[NN],x[NN],c[NN],sa[NN],rk[NN],height[NN];
int n,m,q;
int st[NN][20],lg2[NN];
int troot[NN];
int tot;
int num[NN*40],L[NN*40],R[NN*40];
void build(int &cur,int l,int r){
    cur=++tot;
    num[cur]=0;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    build(L[cur],l,mid);
    build(R[cur],mid+1,r);

}
void add(int &cur,int pre,int l,int r,int val){
    cur=++tot;
    num[cur]=num[pre]+1;
    if(l==r)return;
    L[cur]=L[pre];
    R[cur]=R[pre];
    int mid=(l+r)>>1;
    if(val<=mid)add(L[cur],L[pre],l,mid,val);
    else add(R[cur],R[pre],mid+1,r,val);
}
int ask_kth(int x,int y,int l,int r, int k){//k is always >=1
    if(num[x]-num[y]<k)return -1;
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    int deci=num[L[x]]-num[L[y]];
    if(deci>=k)
        return ask_kth(L[x],L[y],l,mid,k);
    else{
        if(num[R[x]]-num[R[y]]<=0){
            return ask_kth(L[x],L[y],l,mid,deci);
        }
        else return ask_kth(R[x],R[y],mid+1,r,k-deci);
    }
}
void ST() {
    for (int i = 1; i <= n; i++) {
        st[i][0] = height[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; (i + (1 << j) - 1) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 2; i <= n; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
}

int rmq(int l, int r) {
    if (l>r)
        return 0;
    else {
        int x=lg2[r-l+1];
        return min(st[l][x],st[r-(1<<x)+1][x]);
    }
}
void get_SA()
{
    memset(c,0,sizeof(c));
    memset(sa,0,sizeof(sa));
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    for(int i=1;i<=n;++i) ++c[x[i]=s[i]];
    for(int i=2;i<=m;++i) c[i]+=c[i-1];
    for(int i=n;i>=1;--i) sa[c[x[i]]--]=i;
    for(int k=1;k<=n;k<<=1)
    {
        int num=0;
        for(int i=n-k+1;i<=n;++i) y[++num]=i;
        for(int i=1;i<=n;++i) if(sa[i]>k) y[++num]=sa[i]-k;
        for(int i=1;i<=m;++i) c[i]=0;
        for(int i=1;i<=n;++i) ++c[x[i]];
        for(int i=2;i<=m;++i) c[i]+=c[i-1];
        for(int i=n;i>=1;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        swap(x,y);
        x[sa[1]]=1;
        num=1;
        for(int i=2;i<=n;++i)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]) ? num:++num;
        if(num==n) break;
        m=num;
    }
}
void get_height()
{
    int k=0;
    for(int i=1;i<=n;++i) rk[sa[i]]=i;
    for(int i=1;i<=n;++i)
    {
        if(rk[i]==1) continue;
        if(k) --k;
        int j=sa[rk[i]-1];
        while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k]) ++k;
        height[rk[i]]=k;
    }
}
int main(){
    int z;
    scanf("%d\n",&z);
    while(z--){
        scanf("%d%d",&n,&q);
        scanf("%s",ss+1);
        for(int i=1;i<=n;i++){
            s[i]=ss[i]-'a'+1;
        }
        s[n+1]=0;s[n+2]=0;
        m=30;
        get_SA();
        get_height();
    //    for(int i=1;i<=n;i++){
    //        for(int j=sa[i];j<=n;j++){
    //            printf("%d ",s[j]);
    //        }printf("\n");
    //    }
       for(int i=1;i<=n;i++){
           printf("%d\n",height[i]);
       }
        
        
        tot=0;
        build(troot[0],1,n);
        for(int i=1;i<=n;i++){
            add(troot[i],troot[i-1],1,n,sa[i]);
        }
        //printf("*****%d\n",ask_kth(troot[n],troot[0],1,n,5) );
        
        ST();
        for(int i=1;i<=q;i++){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            int ansl=rk[x];int ansr=rk[x];
            int l=1;int r=rk[x];
            while(l<=r){
                int mid=(l+r)>>1;
                if(rmq(mid,rk[x])<y-x+1){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                    ansl=min(ansl,mid-1);
                }
            }
            l=rk[x]+1;r=n;
            while(l<=r){
                int mid=(l+r)>>1;
                if(rmq(rk[x]+1,mid)<y-x+1){
                    r=mid-1;
                }
                else{
                    ansr=max(ansr,mid);
                    l=mid+1;
                }
            }
    //        printf("*%d %d %d\n",rk[x],ansl,ansr);
            int res=ask_kth(troot[ansr],troot[ansl-1],1,n,k);
            printf("%d\n",res);
        }
    }
    return 0;
}