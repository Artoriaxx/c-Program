#include<bits/stdc++.h>
#define N 1005
using namespace std;
const int inf = 0x3f3f3f3f;
struct node {
    int v;
    double w;
    node() {}
    node(int v, int w): v(v), w(w) {}
};
vector<node> G[N];
void dijkstra(int s){
	priority_queue<pi, vector<pi>, greater<pi> > q;
	fill(d + 1, d + 1 + n, inf);
	d[s] = 0;
	fill(vis + 1, vis + n + 1, false);
	q.push(make_pair(d[s], s));
	while(!q.empty()){
		pi now = q.top();
		q.pop();
		int x = now.second;
		if(vis[x]) continue;
		vis[x] = true;
		for(int i = head[x]; i; i = edge[i].next){
			int v = edge[i].v;
			if(d[v] > d[x] + edge[i].w){
				d[v] = d[x] + edge[i].w;
				q.push(make_pair(d[v], v));
			}
		}
	}
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b, c, 
    }
}