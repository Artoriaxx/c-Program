#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int NN=1e5+10;
const int oo=2e9+10;
map<int,double>ma_x;
map<int,double>ma_y;
struct pppp
{
	int x1,y1,x2,y2;
}d[NN];
struct pp
{
	int x,y,px,py;
}bx[NN],by[NN];
bool cmp_x(pp x,pp y){
    return x.x<y.x;
}
bool cmp_y(pp x,pp y){
	return x.y<y.y;
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&d[i].x1,&d[i].y1,&d[i].x2,&d[i].y2);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&bx[i].x,&bx[i].y,&bx[i].px,&bx[i].py);
		by[i]=bx[i];
	}
	sort(bx+1,bx+m+1,cmp_x);
	sort(by+1,by+m+1,cmp_y);
	bx[0].x=oo;
	for(int i=1;i<=m;i++){
		if(bx[i].x!=bx[i-1].x){
			ma_x[bx[i].x]=(100.0-bx[i].py)/100.0;
		}
		else{
			ma_x[bx[i].x]*=(100.0-bx[i].py)/100.0;
		}
	}
    for (map<int,double>::iterator it=ma_x.begin();it!=ma_x.end();++it) {
        it->second = 1.0 - it->second;
    }
	
	for(map<int,double>::iterator it=ma_x.begin();it!=ma_x.end();++it){
		if(it==ma_x.begin())continue;
		else{
			map<int,double>::iterator cur=it;
			map<int,double>::iterator it1=--it;
			cur->second=it1->second+cur->second;
            it = cur;
		}
	}
	by[0].y=oo;
	for(int i=1;i<=m;i++){
		if(by[i].y!=by[i-1].y){
			ma_y[by[i].y]=(100.0-by[i].px)/100.0;
		}
		else{
			ma_y[by[i].y]*=(100.0-by[i].px)/100.0;
		}
	}
    for (map<int,double>::iterator it=ma_y.begin();it!=ma_y.end();++it) {
        it->second = 1.0 - it->second;
    }
    ma_x[-oo] = 0.0;
    ma_y[-oo] = 0.0;
    ma_x[oo] = 0.0;
    ma_y[oo] = 0.0;
	for(map<int,double>::iterator it=ma_y.begin();it!=ma_y.end();++it){
		if(it==ma_y.begin())continue;
		else{
			map<int,double>::iterator cur=it;
			map<int,double>::iterator it1=--it;
			cur->second=it1->second+cur->second;
            it = cur;
		}
	}
	double ans=0.0;
	for(int i=1;i<=n;i++){
		map<int,double>::iterator lowx=ma_x.lower_bound(d[i].x1);--lowx;
		map<int,double>::iterator highx=ma_x.upper_bound(d[i].x2);--highx;
		double px=highx->second-lowx->second;
		ans+=px*(d[i].x2-d[i].x1+1);

		map<int,double>::iterator lowy=ma_y.lower_bound(d[i].y1);--lowy;
		map<int,double>::iterator highy=ma_y.upper_bound(d[i].y2);--highy;
		double py=highy->second-lowy->second;
		ans+=py*(d[i].y2-d[i].y1+1-px);
	}
	printf("%.15f\n",ans);
	return 0;
}