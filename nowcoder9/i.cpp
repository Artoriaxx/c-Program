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
 
const int N=1e5+10;
 
int T,n,cnt[11];
int ans[N],tot;
 
int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 rd(T);
 while(T--){
  rd(n);
  tot=0;
  memset(cnt,0,sizeof(cnt));
  for(int i=1;i<=n;i++){
   int x;rd(x);cnt[x]++;
  }
  int ans2=1;
  while(cnt[ans2] == 0)ans2++;
  cnt[ans2]--;
  int tmp=ans2;
  while(cnt[tmp] == 0)tmp++;
  ans[++tot]=tmp;
  cnt[tmp]--;
  for(int i=0;i<=9;i++){
   if(!cnt[i])continue;
   while(cnt[i]--)ans[++tot]=i;
  }
  int now=0;
  for(int i=tot;i>=1;i--){
   ans[i]=ans[i]*ans2+now;
   now=ans[i]/10;
   ans[i]%=10;
  }
  if(now)printf("%d",now);
  for(int i=1;i<=tot;i++)printf("%d",ans[i]);
  puts("");
 }
 return 0;
}