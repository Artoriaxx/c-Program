#include<bits/stdc++.h>
#define maxn 1000050
#define re register int
using namespace std;
int a[maxn];
inline int getnum() {
	int ans = 0; char c; bool flag = 0;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = 1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int main() {
	int n;
	n = getnum();
	for (re i = 1; i <= n; i++) {
		a[i] = getnum();
	}
	for (re j = 2; j <= n; j++) {
		int now = a[j];
		int i = j - 1;
		while (i >= 1 && a[i] > now) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = now;
	}
	for (re i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}