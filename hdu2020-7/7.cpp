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

const int N=2005;

struct Point{
 int x,y;
 void read(){
  rd(x);rd(y);
 }
}p[N];

LL dis(Point x,Point y){return 1ll*(x.x-y.x)*(x.x-y.x)+1ll*(x.y-y.y)*(x.y-y.y);}

int a[N][N];
int T,n;
bool vis[N];

bool dfs(int x,LL mx){
 for(int i=1;i<=n;i++){
  LL tmp=dis(p[x],p[a[x][i]]);
  if(vis[a[x][i]] ||  tmp <= mx)continue;
  vis[a[x][i]]=1;
  bool is=dfs(a[x][i],tmp);
  vis[a[x][i]]=0;
  if(!is)return 1;
 }
 return 0;
}

int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 rd(T);
 while(T--){
  rd(n);
  for(int i=1;i<=n;i++)p[i].read();
  for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++)
    a[i][j]=j;
   random_shuffle(a[i]+1,a[i]+n+1);
  }
  vis[1]=1;
  for(int i=2;i<=n;i++)vis[i]=0;
  if(dfs(1,-1))printf("YES\n");
  else printf("NO\n");
 }
 return 0;
}