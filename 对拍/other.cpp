#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 21;
struct hh{
	int hh,mm;
	bool flag;
}a[MAX],b[MAX];
bool vis[MAX];
int n,ans,hhh,mmm;
hh jisuan(hh a,hh b){//转换成分进行计算
	hh w;
	int tt;
	int t1=a.hh*60+a.mm;
	int t2=(b.hh%12)*60+b.mm;//题目说小时范围为10000，注意一下
	if(b.flag==false) tt=t1+t2;
	else tt=t1-t2;
	if(tt<0) tt+=720;//小于0相当于再加12个小时，很好理解，推一下就好
	w.hh=tt/60%12;//别忘了%12，这里加的时候可能会超过12个小时
	w.mm=tt%60;
	if(w.hh==0) w.hh=12;
	return w;
}
void dfs(int cnt,int h,int m){//搜索
	if(cnt==n){
		if(!ans) {//第一次符合要求
			ans++;
			hhh=h;
			mmm=m;
		}
		else if(h!=hhh||m!=mmm) ans++;//其他符合的要求
		return;
	}
	for (int i = 0; i < n;i++){
		if(!vis[i]){//注意标记
			hh w;
			w=jisuan(a[cnt],b[i]);
			if(!cnt||w.hh==h&&w.mm==m){//注意第一次的处理
				vis[i]=true;//标记不重复用，因为一个对应一个，题目要求的
				dfs(cnt+1,w.hh,w.mm);
				vis[i]=false;
			}
		}
	}
	return;
}
int main(){
	int p,k;
	char ch;
	scanf("%d",&p);
	while(p--){
		scanf("%d%d",&k,&n);
		for (int i = 0; i < n;i++) scanf("%d:%d",&a[i].hh,&a[i].mm);
		for (int i = 0; i < n;i++) {
			getchar();
			scanf("%c%d:%d",&ch,&b[i].hh,&b[i].mm);
			if(ch=='-') b[i].flag=false;
			else b[i].flag=true;
		}
		memset(vis,0,sizeof(vis));//别忘了初始化
		ans=0;
		dfs(0,0,0);
		printf("%d ",k);
		if(ans==0) printf("none\n");
		else if(ans==1) printf("%d:%02d\n",hhh,mmm);
		else printf("%d\n",ans);
	}
	return 0;
}