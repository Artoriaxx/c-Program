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
const int M=5e5+10;
using namespace std;
LL n;
int m;
int L[M],R[M];
char c[M];
LL cnt[M];
int in[M];
queue<int>S;
char tmp[2];
int main(){
// freopen("in.txt","r",stdin);
 lrd(n);rd(m);
 for(int i=1;i<=m;i++){
  scanf("%s%d%d",tmp,&L[i],&R[i]);
  c[i]=tmp[0];in[L[i]]++;in[R[i]]++;
 }
 for(int i=1;i<=m;i++)if(!in[i])S.push(i);
 cnt[1]=n;
 while(!S.empty()){
  int u=S.front();S.pop();if(!u)break;
  if(c[u] == 'L')cnt[L[u]]+=(cnt[u]+1)/2,cnt[R[u]]+=cnt[u]/2;
  else cnt[L[u]]+=cnt[u]/2,cnt[R[u]]+=(cnt[u]+1)/2;
  in[L[u]]--;
  if(!in[L[u]])S.push(L[u]);
  in[R[u]]--;
  if(!in[R[u]])S.push(R[u]);
 }
 for(int i=1;i<=m;i++){
  if(cnt[i]%2==1){
   if(c[i] == 'L')putchar('R');
   else putchar('L');
  }
  else putchar(c[i]);
 }
 return 0;
 multiset<int>::iterator it
}
/**/