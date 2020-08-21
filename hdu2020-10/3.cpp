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

const int N=30;

int T;
int S;

int a[N][N];

void out(int n,int m){
 printf("%d %d\n",n,m);
 for(int i = 1;i <= n;i++) {
  for(int j = 1;j <= m;j++) {
    printf("%c",a[i][j]?'X':'.');
  }
  puts("");
 }
}

void col(int x){
 for(int i = 3;i <= 23;i+=2)
  for(int j = 3;j <= 23;j+=2){
   if(!x){out(25,25);return ;}
   a[i][j]=1;
   x--;
  }
 for(int i = 4;i <= 22;i += 4){
  if(!x){out(25,25);return ;}
  a[3][i]=1;a[3][i+2]=1;
  x--;
 }
}

void work(){
 memset(a,0,sizeof(a));
 if(S == 0){
  out(1,1);
  return ;
 }
 if(S == 1){
  a[1][1]=1;
  out(1,2);
  return ;
 }
 if(S == 2){
  a[1][2]=1;
  out(1,3);
  return ;
 }
 if(S == 3){
  a[1][1]=1;
  out(2,2);
  return ;
 }
 if(S == 4){
  a[1][1]=1;
  a[2][1]=1;
  out(2,2);
  return ;
 }
 if(S == 5){
  a[2][1]=1;
  out(3,2);
  return ;
 }
 if(S == 6){
  a[1][1]=1;
  a[2][1]=1;
  out(3,2);
  return ;
 }
 if(S == 7){
  a[1][3]=1;
  a[2][1]=1;
  a[2][2]=1;
  out(2,3);
  return ;
 }
 if(S == 8){
  a[2][2]=1;
  out(3,3);
  return ;
 }
 if(S == 9){
  a[1][1]=1;
  a[1][4]=1;
  a[4][1]=1;
  out(4,4);
  return ;
 }
 if(S == 10){
  a[2][1]=1;
  a[2][3]=1;
  out(3,3);
  return ;
 }
 if(S == 11){
  a[2][1]=1;
  a[3][1]=1;
  a[4][1]=1;
  out(5,2);
  return ;
 }
 if(S == 12){
  a[1][1]=1;
  a[1][4]=1;
  a[4][1]=1;
  a[4][4]=1;
  out(4,4);
  return ;
 }
 if(S == 13){
  a[2][1]=1;
  a[2][3]=1;
  out(3,4);
  return ;
 }
 if(S == 14){
  a[1][1]=1;
  a[4][1]=1;
  a[2][4]=1;
  out(4,5);
  return ;
 }
 if(S == 15){
  a[2][1]=1;
  a[2][3]=1;
  a[4][2]=1;
  out(4,3);
  return ;
 }
 if(S == 16){
  a[2][2]=1;
  a[2][4]=1;
  out(3,5);
  return ;
 }
 if(S == 17){
  a[1][1]=1;
  a[1][3]=1;
  a[1][5]=1;
  a[3][1]=1;
  a[3][5]=1;
  out(3,5);
  return ;
 }
 if(S == 18){
  a[1][1]=1;
  a[1][3]=1;
  a[1][5]=1;
  a[1][7]=1;
  out(2,8);
  return ;
 }
 if(S == 19){
  for(int i = 1;i <= 7;i++)
   a[1][i]=1;
  out(2,7);
  return ;
 }
 if(S == 20){
  a[1][1]=a[1][5]=1;
  a[2][3]=1;
  a[3][1]=a[3][5]=1;
  out(3,5);
  return ;
 }
 if(S == 21){
  a[2][1]=a[2][3]=a[2][5]=1;
  out(3,6);
  return ;
 }
 if(S == 22){
  a[1][1]=1;
  a[2][3]=a[2][5]=1;
  a[3][1]=1;
  out(3,6);
  return ;
 }
 if(S == 23){
  a[2][1]=a[2][3]=a[2][5]=1;
  a[4][3]=1;
  out(4,5);
  return ;
 }
 int u = S % 8,v = S / 8;
 if(u == 0){col(v);return ;}
 a[1][1]=1;
 if(u == 3){col(v);return ;}
 a[2][1]=1;
 if(u == 6){col(v);return ;}
 a[1][25]=1,v--;
 if(u == 1){col(v);return ;}
 a[2][25]=1;
 if(u == 4){col(v);return ;}
 a[25][1]=1;
 if(u == 7){col(v);return ;}
 a[24][1]=1;v--;
 if(u == 2){col(v);return ;}
 a[25][25]=1;
 if(u == 5){col(v);return ;}
}

int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 rd(T);
 while(T--){
  rd(S);
  work();
 }
 return 0;
}