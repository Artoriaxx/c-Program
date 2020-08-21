#include<bits/stdc++.h>
#define LL long long
#define dl double
void rd(int &x){
 x=0;int f=1;char ch=getchar();
 while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch<='9' && ch>='0')x=x*10+ch-'0',ch=getchar();x*=f;
}
void lrd(LL &x){
 x=0;int f=1;char ch=getchar();
 while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch<='9' && ch>='0')x=x*10+ch-'0',ch=getchar();x*=f;
}
const int INF=1e9;
const LL LINF=1e18;
const int N=1e5+10;
const dl eps=1e-10;
using namespace std;
int Rand(int x){return ((rand()<<10)+rand())%x+1;}
int n,p,node;
LL x[N],y[N];
bool check(int u,int v){
 int cnt=0;
 if(x[u] == x[v]){
  for(int i=1;i<=n;i++)
   if(x[i] == x[u])cnt++;
  return cnt >= node;
 }
 else {
  for(int i=1;i<=n;i++){
   if(x[i] == x[u])continue;
   if((y[u]-y[v])*(x[u]-x[i]) == (y[u]-y[i])*(x[u]-x[v]))cnt++;
  }
  return cnt+1 >= node;
 }
}
int main(){
// freopen("in.txt","r",stdin);
 srand(time(NULL));
 rd(n);rd(p);for(int i=1;i<=n;i++)lrd(x[i]),lrd(y[i]);
 node=ceil(1.0*n*p/100);
 if(n == 1){
     printf("possible\n");
     exit(0);
 }
 else if(n <= 400){
  for(int u=1;u<n;u++)
   for(int v=u+1;v<=n;v++)
    if(check(u,v)){
        printf("possible\n");
        exit(0);
    }
  printf("impossible\n");
 }
 else {
  for(int i=1;i<=1000;i++){
   int u=Rand(n),v=Rand(n);
   while(u==v)v=Rand(n);
   if(check(u,v)){
       printf("possible\n");
       exit(0);
   }
  }
  printf("impossible\n");
 }
 return 0;
}