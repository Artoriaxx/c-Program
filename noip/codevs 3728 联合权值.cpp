#include<iostream>
#define ll long long
#define maxn 200010
#define p 10007
using namespace std;
struct edge{
	int v,next;
}edge[maxn * 2];
int head[maxn], num = 0, w[maxn];
ll ans1;ll ans2;ll sum;
inline void addedge(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int main(){
	int n, a, b;
	cin >> n;
	for(int i = 1; i <= n - 1; i++){
		cin>>a>>b;
		addedge(a, b);
		addedge(b, a);
	}
	for(int i = 1; i <= n; i++){
		cin>>w[i];
	}
	for(int i = 1; i <= n; i++){
		ll max1 = -1;ll max2 = -1;
		sum = 0;
		for(int j = head[i]; j; j = edge[j].next){
			int v = edge[j].v;
			sum += w[v];//加的时候不要取模，会导致答案出现负数，否则加上p再%p也可解决负数问题 
			if(w[v] >= max1){
				max2 = max1;
				max1 = w[v];
			}
			else if(w[v] >= max2){
				max2 = w[v];
			}
		}
		ans2 = max(ans2, max1 * max2);
		for(int j = head[i]; j; j = edge[j].next){
			int v = edge[j].v;
			(ans1 += w[v] * (sum - w[v])) %= p;
		}
	}
	cout<<ans2<<" "<<ans1<<endl;
	return 0;
}
