#include <bits/stdc++.h>
using namespace std;
const int mod = 12 * 60;
char ch[100];
int tt[20];
int vis[20];
int k, n;
int xuan[20];
int a[20][20];
int ans[20];
int num = 0;
void dfs(int cnt, int time) {
	if (cnt > n) {
		if (num == 0) ans[++num] = time;
		else ++num;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (cnt == 1) {
				vis[i] = 1;
				dfs(cnt + 1, a[cnt][i]);
				vis[i] = 0;
			}
			else if (a[cnt][i] == time) {
				vis[i] = 1;
				dfs(cnt + 1, a[cnt][i]);
				vis[i] = 0;
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int cnt = 0;
		scanf("%d%d", &k, &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", ch + 1);
			int len = strlen(ch + 1);
			bool flag = false;
			int hour = 0, min = 0;
			for (int j = 1; j <= len; j++) {
				if (ch[j] != ':') {
					if (!flag) {
						hour = hour * 10 + ch[j] - '0';
					}
					else {
						min = min * 10 + ch[j] - '0';
					}
				}
				else flag = true;
			}
			int time = hour * 60 + min;
			tt[i] = time;
		}
		num = 0;
		memset(xuan, 0, sizeof(xuan));
		memset(ans, 0, sizeof(ans));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			scanf("%s", ch + 1);
			int len = strlen(ch + 1);
			bool flag = false;
			int hour = 0, min = 0;
			for (int j = 2; j <= len; j++) {
				if (ch[j] != ':') {
					if (!flag) {
						hour = hour * 10 + ch[j] - '0';
					}
					else {
						min = min * 10 + ch[j] - '0';
					}
				}
				else flag = true;
			}
			int time = (hour % 12) * 60 + min;
			if (ch[1] == '+') {
				for (int k = 1; k <= n; k++) {
					a[k][0]++;
					a[k][a[k][0]] = (tt[k] - time + mod) % mod;
				}
			}
			else if (ch[1] == '-') {
				for (int k = 1; k <= n; k++) {
					a[k][0]++;
					a[k][a[k][0]] = (tt[k] + time) % mod;
				}
			}
		}
		/*if (n == 1) {
			int hour = a[1][1] / 60;
			int min = a[1][1] - hour * 60;
			cout << k << " ";
			printf("%d:%02d\n", hour, min);
			continue;
		}*/
		dfs(1, 0);
		
		cout << k << " ";
		if (num == 0) {
			cout << "none" << endl;
		}
		else if (num == 1) {
			int hour = ans[1] / 60 % 12;
			int min = ans[1] % 60;
			if (hour == 0) hour = 12;
			printf("%d:%02d\n", hour, min);
		}
		else {
			cout << num << endl;
		}
	}
	return 0;
}