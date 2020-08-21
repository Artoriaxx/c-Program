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
 
int T;
int n,k;
 
void work1(){
 int now=0;
 for(int i=1;i<=(n+1)*2;i++){
  for(int j=1;j<=n;j++){
   now%=k;
   printf("%d ",++now);
  }
  puts("");
 }
}
 
void work2(){
 int now=0;
 for(int i=1;i<=(n+1)*2;i++){
  now++;
  int tmp;
  if(now&1)tmp=0;else tmp=1;
  for(int j=1;j<=n;j++){
   printf("%d ",++tmp);
   tmp=tmp%k;
  }
  puts("");
 }
}
 
int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 rd(T);
 while(T--){
  rd(n);rd(k);
  if(k == 1 || n == 1){printf("-1\n");continue;}
  if(2*n*(n+1) % k){printf("-1\n");continue;}
  if(n % k)work1();
  else work2();
 }
 return 0;
}