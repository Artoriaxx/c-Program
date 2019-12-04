#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200050;
struct node{
	int a,b,c;
	bool operator < (const node &x) const {
		return c > x.c;
	}
}a[maxn];
int fa[maxn];
inline int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}

int c[maxn];
int main(){
//	freopen("equ.in", "r", stdin);
//	freopen("equ.out", "w", stdout);
	int T = getnum();
	while(T--){
		int n = getnum();
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			a[i].a = getnum();
			a[i].b = getnum();
			a[i].c = getnum();
			c[++cnt] = a[i].a;
			c[++cnt] = a[i].b;
		}
		
		sort(a + 1, a + n + 1);
		sort(c + 1, c + cnt + 1);
		cnt = unique(c + 1, c + cnt + 1) - c - 1;
		
		for(int i = 1; i <= cnt; i++) fa[i] = i;
		
		bool flag = false;
		for(int i = 1; i <= n; i++){
			int x = lower_bound(c + 1, c + cnt + 1, a[i].a) - c;
			int y = lower_bound(c + 1, c + cnt + 1, a[i].b) - c;
			if(a[i].c == 1){
				fa[find(x)] = find(y);
			}
			else{
				if(find(x) == find(y)){
					flag = true;
					break;
				}
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
}
