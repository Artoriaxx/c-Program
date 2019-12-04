#include<bits/stdc++.h>
#define maxn 200020
using namespace std;
int n, k, p;
inline int getnum(){
    int ans = 0; bool flag = false; char c;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') flag = true; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * (flag ? -1 : 1);
}
int pi[maxn], col[maxn];
struct segment_tree{
#define lson (o << 1)
#define rson (o << 1 | 1)
    int minv[maxn << 2];
    inline void pushup(int o){
        minv[o] = min(minv[lson], minv[rson]);
    }
    inline void build(int o, int l, int r){
        int mid = (l + r) >> 1;
        if (l == r){
            minv[o] = pi[l];
            return;
        }
        build(lson, l, mid), build(rson, mid + 1, r);
        pushup(o);
    }
    inline int query(int o, int l, int r, int ql, int qr){
        if (ql <= l && r <= qr){
            return minv[o];
        }
        int mid = (l + r) >> 1, minans = 0x3f3f3f3f;
        if (ql <= mid) minans = min(minans, query(lson, l, mid, ql, qr));
        if (qr > mid) minans = min(minans, query(rson, mid + 1, r, ql, qr));
        return minans;
    }
} t;
vector<int> vis[150];
int main(){
	freopen("testdata (2).in", "r", stdin);
    n = getnum(), k = getnum(), p = getnum();
    for (int i = 1; i <= n; i++){
        col[i] = getnum(), pi[i] = getnum();
        vis[col[i]].push_back(i);
    }
    t.build(1, 1, n);
    int ans = 0;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < vis[i].size(); j++){
        	for (int x = j + 1; x < vis[i].size(); x++){
        		int l = vis[i][j], r = vis[i][x];
        		if (t.query(1, 1, n, l, r) <= p){
        			ans += vis[i].size() - x;
        			break;
        		}
        	}
        }
    }
    printf("%d", ans);
    return 0;
}
