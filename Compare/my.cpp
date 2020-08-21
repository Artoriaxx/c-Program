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
const int N=15;
using namespace std;
int n,T,mn;
char s[N];
int a[N];
bool check(){
 int cnt1=0,cnt2=0,id1=0,id2=0;
 for(int i=0;i<n;i++)
  if(a[i]){
   cnt1++;
   if(cnt1 == 3){
    id1=i;break;
   }
  }
 for(int i=n-1;i>=0;i--)
  if(!a[i]){
   cnt2++;
   if(cnt2 == 2){
    id2=i;break;
   }
  }
 if(!id1 || !id2)return 1;
 return id1 > id2;
}
void dfs(int x,int y){
 if(x == n){
  if(!check())return ;
  mn=min(mn,y);
  return ;
 }
 dfs(x+1,y);
 a[x]^=1;
 dfs(x+1,y+1);
 a[x]^=1;
}
int main(){
// freopen("in.txt","r",stdin);
 rd(T);
 while(T--){
  scanf("%s",s);n=strlen(s);
  for(int i=0;i<n;i++)
   if(s[i] == 'x')a[i]=1;
   else a[i]=0;
  mn=100;dfs(0,0);
  printf("%d\n",mn);
 }
 return 0;
}