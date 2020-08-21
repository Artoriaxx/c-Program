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

const int N=1e6+10;

int T;
int n,k,m;
vector<int>S[N];
int b[N];

int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 rd(T);
 b[0]=1;for(int i=1;i<=11;i++)b[i]=b[i-1]*2;
 while(T--){
  rd(n);rd(k);
  m=n*b[k+1];
  for(int i=1;i<=m;i++){
   S[i].clear();
   int x;rd(x);
   S[i].push_back(x);
  }
  while(k--){
   for(int i=m-n*b[k+1]+1;i<=m;i++){
    int j=2*(m-n*b[k+1])-i+1;
    for(int x=S[j].size()-1;x>=0;x--)S[i].push_back(S[j][x]);
   }
  }
  for(int i=m-2*n+1;i<=m;i++){
   for(int j=S[i].size()-1;j>=0;j--)
    if(i==m&&j==0) printf("%d\n",S[i][j]);
    else printf("%d ",S[i][j]);
  }
 }
 return 0;
}