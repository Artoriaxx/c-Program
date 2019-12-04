#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n;
int binary_search(int x) {
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (a[mid] == x) return mid;
		else if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}
int main() {
	freopen("2.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int x;
	scanf("%d", &x);
	int ans = binary_search(x);
	if (ans == -1) {
		printf("NOT FOUND\n");
	}
	else {
		printf("%d\n", ans);
	}
	return 0;
}