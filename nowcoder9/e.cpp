#include<bits/stdc++.h>
#define int long long
#define LL long long
#define dl double
 
template <class T>
void rd(T &x){
 x=0;T f=1;char ch=getchar();
 while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch<='9' && ch>='0')x=x*10+ch-'0',ch=getchar();x*=f;
}
 
using namespace std;
 
const int mod=998244353;
 
int gcd(int x,int y){return !y ? x : gcd(y,x%y);}
int fst(int x,__int128 y){int ret;for(ret=1;y;y/=2,x=1ll*x*x%mod)if(y&1)ret=1ll*ret*x%mod;return ret;}
 
struct ghb{
 int val,cntx,cnty;
};
 
vector<ghb>S;
 
int a,b,c,d,x,y;
 
void work(){
 rd(a);rd(b);rd(c);rd(d);rd(x);rd(y);
 int gc=gcd(x,y);
 for(int i=2;i*i<=gc;i++){
  if(gc % i)continue;
  while(gc%i == 0)gc/=i;
  int cnt1=0,cnt2=0;
  while(x % i == 0)cnt1++,x/=i;
  while(y % i == 0)cnt2++,y/=i;
  S.push_back((ghb){i,cnt1,cnt2});
 }
 if(gc > 1){
  int cnt1=0,cnt2=0;
  while(x % gc == 0)cnt1++,x/=gc;
  while(y % gc == 0)cnt2++,y/=gc;
  S.push_back((ghb){gc,cnt1,cnt2});
 }
 int ANS=1;
 for(int i=0;i<S.size();i++){
  ghb now=S[i];
  __int128 ans=0;
  for(int o=a;o<=b;o++){
   if(o*now.cntx <= c*now.cnty)ans+=1ll*o*now.cntx*(d-c+1);
   else if(o*now.cntx >= d*now.cnty);
   else {
    int tmp=o*now.cntx/now.cnty;
    ans+=1ll*o*now.cntx*(d-tmp);
    //ans+=1ll*(c+tmp)*(tmp-c+1)/2*now.cnty;
   }
  }
  for(int o=c;o<=d;o++){
   if(o*now.cnty <= a*now.cntx)ans+=1ll*o*now.cnty*(b-a+1);
   else if(o*now.cnty >= b*now.cntx);
   else {
    int tmp=o*now.cnty/now.cntx;
    ans+=1ll*o*now.cnty*(b-tmp);
    //ans+=1ll*(c+tmp)*(tmp-c+1)/2*now.cnty;
   }
  }
  ANS=1ll*ANS*fst(now.val,ans)%mod;
 }
 printf("%lld\n",ANS);
}
 
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 work();
 return 0;
}
