#include<bits/stdc++.h>
#define maxn 1000050
#define p 99999997
using namespace std;
struct node {
	long long val;
	int pos;
} a[maxn], b[maxn];
inline long long getnum() {
	long long ans = 0; char c; bool flag = 0;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = 1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int li[maxn], ri[maxn];
int cnt;
void merge(int *a, int l, int mid, int r) {
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int maxl = 0x7fffffff;
	for (int i = 1; i <= n1; i++)
		li[i] = a[l + i - 1];
	for (int i = 1; i <= n2; i++)
		ri[i] = a[mid + i];
	li[n1 + 1] = maxl;
	ri[n2 + 1] = maxl;
	for (int k = l, i = 1, j = 1; k <= r; k++) {
		if (li[i] <= ri[j]) {
			a[k] = li[i];
			i++;
		}
		else {
			a[k] = ri[j];
			j++;
			if (i <= n1) cnt += n1 - i + 1;
		}
	}
}
void merge_sort(int *a, int l, int r) {
	if (l < r) {
		int mid = (l + r) >> 1;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}
bool cmp(node a, node b) {
	return a.val < b.val;
}
int now[maxn];
int main() {
	int n = getnum();
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		a[i].val = getnum();
		a[i].pos = i;
	}
	for (int i = 1; i <= n; i++) {
		b[i].val = getnum();
		b[i].pos = i;
	}
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		now[b[i].pos] = a[i].pos;
	}
	merge_sort(now, 1, n);
	printf("%d", cnt % p);
	return 0;
}