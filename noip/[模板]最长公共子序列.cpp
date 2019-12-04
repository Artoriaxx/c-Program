#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 100050
using namespace std;
int maps[maxn], f[maxn];
int a[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int ai;
		scanf("%d", &ai);//将最长公共子序列转换为最长上升子序列 
		maps[ai] = i;
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] = maps[a[i]];
	}
	fill(f, f + n + 1, inf);
	for (int i = 1; i <= n; i++){
		*lower_bound(f + 1, f + n + 1, a[i]) = a[i];
	}
	int ans = lower_bound(f + 1, f + n + 1, inf) - f - 1;
	printf("%d", ans);
	return 0;
}
