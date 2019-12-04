#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 100050
using namespace std;
inline int getnum(){
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
struct node{
	int v, pos;
	bool operator < (const node &t) const {
		return v < t.v;
	}
}a[maxn];
int vis[maxn];
int tmp[maxn], tmp1[maxn];
int main(){
	priority_queue<node> q;
	int n;
	n = getnum();
	for (register int i = 1; i <= n; i++){
		a[i].v = getnum();
		a[i].pos = i;
		q.push(a[i]);
	}
	while (!q.empty()){
		node s = q.top(); q.pop();
		int pos = s.pos;
		if (vis[pos] || pos == n) continue;
		int cnt = pos + 1;
		while (vis[cnt]){
			cnt++;
		}
		if (cnt <= n){
			cout << a[pos].v << " ";
			cout << a[cnt].v << " ";
			vis[pos] = 1;
			vis[cnt] = 1;
		}
	}
	return 0;
}
