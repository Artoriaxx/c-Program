#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
	int l = -1, r = -1, val = -1;
} tree[N];
int cnt = 1;
void insert(int x, int root) {
	if (tree[root].val == -1) {
		tree[root].val = x;
		return;
	}
	else {
		if (x >= tree[root].val) {
			if (tree[root].r != -1) insert(x, tree[root].r);
			else {
				tree[root].r = ++cnt;
				insert(x, tree[root].r);
			}
		}
		if (x < tree[root].val) {
			if (tree[root].l != -1) insert(x, tree[root].l);
			else {
				tree[root].l = ++cnt;
				insert(x, tree[root].l);
			}
		}
	}
}
void dfs(int root) {
	if (tree[root].l != -1) dfs(tree[root].l);
	printf("%d ", tree[root].val);
	if (tree[root].r != -1) dfs(tree[root].r);
}
int main() {
	freopen("1.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		insert(x, 1);
	}
	dfs(1);
	return 0;
}