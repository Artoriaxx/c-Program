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
const int N=105;
using namespace std;
int T,n;
char s[N];
int main(){
// freopen("in.txt","r",stdin);
 rd(T);
 while(T--){
  scanf("%s",s);n=strlen(s);
  int cnt=0,ans1=0,ans2=0;
  for(int i=0;i<n;i++)
   if(s[i] == 'x')cnt++;
   else if(cnt >= 3)ans1++;
  ans1=max(0,ans1-1);
  cnt=0;
  for(int i=n-1;i>=0;i--)
   if(s[i] == 'l')cnt++;
   else if(cnt >= 2)ans2++;
  ans2=max(0,ans2-2);
  printf("%d\n",min(ans1,ans2));
 }
 return 0;
}
/**/
