#include<bits/stdc++.h>
#define LL long long
#define dl double
template <class T>
void rd(T &x){
  x=0;T f=1;char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch<='9' && ch>='0')x=x*10+ch-'0',ch=getchar();x*=f;
}

using namespace std;

const int N=55;

int T;
int n,k,ans;
int a[N][N];
bool is[N][N],vis[N];
int dis[N];
queue<int>S;

void spfa(int ghb){
 memset(dis,0x3f,sizeof(dis));
 dis[1]=0;S.push(1);vis[1]=1;
 while(!S.empty()){
  int x=S.front();S.pop();vis[x]=0;
  for(int i=1;i<=n;i++){
   if(is[x][i])continue;
   if(dis[i] > dis[x]+a[x][i]){
    dis[i]=dis[x]+a[x][i];
    if(!vis[i])S.push(i),vis[i]=1;
   }
  }
 }
 ans=max(ans,dis[n]);
 if(ghb == k+1)return ;
 int now=n,mn=0x7fffffff,fro=0,to=0;
 while(now != 1){
  for(int i=1;i<=n;i++){
   if(is[i][now])continue;
   if(dis[i]+a[i][now] == dis[now]){
    if(a[i][now] < mn){
     mn=a[i][now];
     fro=i;to=now;
    }
    now=i;break;
   }
  }
 }
 is[fro][to]=is[to][fro]=1;
}

void work(){
 for(int i=1;i<=k+1;i++)spfa(i);
}

int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 rd(T);
 while(T--){
  rd(n);rd(k);ans=0;
  memset(is,0,sizeof(is));
  for(int i=1;i<=n;i++)
   for(int j=i+1;j<=n;j++){
    int x,y,z;rd(x);rd(y);rd(z);
    a[x][y]=a[y][x]=z;
   }
  work();
  printf("%d\n",ans);
 }
 return 0;
}
/**/