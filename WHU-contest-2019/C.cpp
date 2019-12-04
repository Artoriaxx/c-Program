#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
int minn[800100];
const int oo=2000000000;
void update(int cur){
	minn[cur]=min(minn[cur<<1],minn[cur<<1|1]);
}
void add(int l,int r,int pos,int val,int cur){
	if(l==r){
		minn[cur]=val;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)add(l,mid,pos,val,cur<<1);
	else add(mid+1,r,pos,val,cur<<1|1);
	update(cur);	
}
int ask(int l,int r,int x,int y,int com,int cur){
	//printf("%d %d %d\n",l,r,minn[cur]);
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	int res1=-1,res2=-1;
	if(x<=mid&&minn[cur<<1]<=com){
		res1=ask(l,mid,x,y,com,cur<<1);
	}
	if(res1==-1&&y>mid&&minn[cur<<1|1]<=com){
		res2=ask(mid+1,r,x,y,com,cur<<1|1);
	}
	if(res1==-1)return res2;
	else return res1;
}
int main(){
	for(int i=1;i<=800000;i++)minn[i]=oo;
	scanf("%d%d",&n,&q);
	int cnt=0;
	for(int i=1;i<=q;i++){
		char s[2];
		scanf("%s",s);
		if(s[0]=='M'){
			int da,id;
			scanf("%d%d",&da,&id);
			add(1,n,id,da,1);
		}
		else{
			int da,id;
			scanf("%d%d",&da,&id);
			int ans=ask(1,n,id,n,da,1);
			printf("%d\n",ans);
		}
	}
}