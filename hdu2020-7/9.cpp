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

int T;
int n,x,y;
vector<int>S[N];

int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 rd(T);
 while(T--){
  rd(n);rd(x);rd(y);
  if(x*y < n || x+y > n+1)printf("NO\n");
  else {
   int now=n;
   for(int i=1;i<=x;i++){
    int len=min(y,now-(x-i));
    for(int j=1;j<=len;j++)S[x-i+1].push_back(now--);
   }
   printf("YES\n");
   for(int i=1;i<=x;i++){
    for(int j=0;j<S[i].size();j++)printf("%d%c",S[i][j],i==x&&j==S[x].size()-1?'\n':' ');
    S[i].clear();
   }
  }
 }
 return 0;
}