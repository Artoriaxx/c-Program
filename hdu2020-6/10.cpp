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

const int N=105;
const int mod=998244353;

LL K[N][N];
LL gauss(int n)
{ //求矩阵K的n-1阶顺序主子式
 LL res = 1;

 for (int i = 1; i <= n - 1; i++)
 { //枚举主对角线上第i个元素

  for (int j = i + 1; j <= n - 1; j++)
  { //枚举剩下的行
   while (K[j][i])
   { //辗转相除
    int t = K[i][i] / K[j][i];
    for (int k = i; k <= n - 1; k++) //转为倒三角
     K[i][k] = (K[i][k] - t * K[j][k] + mod) % mod;
    swap(K[i], K[j]); //交换i、j两行
    res = -res;       //取负
   }
  }
  res = (res * K[i][i]) % mod;
 }
 return (res + mod) % mod;
}

struct edge{
 int fro,to,cst;
 void read(){rd(fro);rd(to);rd(cst);}
}e[N*N];

int T;
int n,m;

int fst(int x,int y){int ret=1;for(;y;y/=2,x=1ll*x*x%mod)if(y&1)ret=1ll*ret*x%mod;return ret;}

int work(int x){
 memset(K,0,sizeof(K));
 for(int i=1;i<=m;i++){
  if((e[i].cst & x)==0)continue;
  K[e[i].fro][e[i].fro]++;
  K[e[i].to][e[i].to]++;
  K[e[i].fro][e[i].to]--;
  K[e[i].to][e[i].fro]--;
 }
 return 1ll*gauss(n)*x%mod;
}

int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 rd(T);
 while(T--){
  rd(n);rd(m);
  for(int i=1;i<=m;i++)e[i].read();
  int ans=0;
  for(int i=0,now=1;i<30;i++,now*=2)ans=(ans+work(now))%mod;
  memset(K,0,sizeof(K));
  for(int i=1;i<=m;i++){
   K[e[i].fro][e[i].fro]++;
   K[e[i].to][e[i].to]++;
   K[e[i].fro][e[i].to]--;
   K[e[i].to][e[i].fro]--;
  }
  ans=1ll*ans*fst(gauss(n),mod-2)%mod;
  printf("%d\n",ans);
 }
 return 0;
}