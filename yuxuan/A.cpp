#include <bits/stdc++.h>
#define N 100005
using namespace std;
struct node {
	int a, b;
	bool operator < (const node &c) const {
		return b - a < c.b - c.a;
	}
} p[N];
int main() {
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) scanf("%d", &p[i].a);
		for (int i = 1; i <= n; i++) scanf("%d", &p[i].b);
		sort (p + 1, p + n + 1);
		long long res = 0;
		for (int i = 1; i <= n / 3; i++) {
			res += 2 * p[i].a;
		}
		for (int i = n / 3 + 1; i <= n * 2 / 3; i++) {
			res += p[i].a + p[i].b;
		}
		for (int i = n * 2 / 3 + 1; i <= n; i++) {
			res += 2 * p[i].b;
		}
		if (res % 2 == 1) printf("%.1f\n", (double)res / 2.0);
		else printf("%lld\n", res / 2);
	}
	
	return 0;
}