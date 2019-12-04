#include<iostream>
#include<algorithm>
#define maxn 1000050
using namespace std;
struct node{
	int pos,val;
	bool type;
}umi[maxn];
int cmp(node a,node b){
	return a.pos < b.pos;
}
int cnt;
long long ans,now,top;
int main(){
	int n, k, q;
	cin>>n>>k>>q;
	int a,b;
	for(int i = 1; i <= n; i++){
		cin>>a>>b;
		umi[++cnt] = (node){a, 1, 0};
		umi[++cnt] = (node){b + 1, -1, 0};
	}
	for(int i = 1; i <= q; i++){
		cin>>a>>b;
		umi[++cnt] = (node){a, i, 1};
		umi[++cnt] = (node){b + 1, -i ,1};
	}
	sort(umi + 1, umi + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i++){
		if(top >= k){
			ans += now * (umi[i].pos - umi[i - 1].pos);
		}
		node m = umi[i];
		if(m.type) now += m.val;
		else top += m.val;
	}
	cout<<ans;
	return 0;
}
