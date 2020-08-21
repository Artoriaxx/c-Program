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

int get(char c){
 if(c=='+' || c=='-' || c=='*' || c=='/' || c=='=')return -1;
 if(c >= '0' && c <='9')return c-'0';
 else return c-'A'+10;
}
int ghb(char c){
 if(c=='+')return 1;
 if(c=='-')return 2;
 if(c=='*')return 3;
 if(c=='/')return 4;
}

int n;
char s[20];
LL ans[3];

bool check(int x){
 if(x == 1)return ans[0]+ans[1] == ans[2];
 if(x == 2)return ans[0]-ans[1] == ans[2];
 if(x == 3)swap(ans[0],ans[2]);
 if(ans[1] == 0)return ans[0]==0;
 return ans[0]/ans[1] == ans[2] && ans[0]%ans[1] == 0;
}

int main(){
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);
 while(scanf("%s",s) != EOF){
  n=strlen(s);
  bool flg=0;
  for(int r=2;r<=16;r++){
   int cnt=0,tmp=0;
   bool f2 = 1;
   memset(ans,0,sizeof(ans));
   for(int i=0;i<n;i++){
    if(get(s[i])==-1){
     if(!tmp)tmp=ghb(s[i]);
     cnt++;
     continue;
    }
    ans[cnt]=ans[cnt]*r+get(s[i]);
    if (get(s[i]) >= r) {
        f2 = 0;
        break;
    }
   }
   if(f2 && check(tmp)){flg=1;printf("%d\n",r);break;}
  }
  if(!flg)printf("-1\n");
 }
 return 0;
}
/**/