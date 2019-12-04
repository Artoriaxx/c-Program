#include<bits/stdc++.h>
using namespace std;
inline int getnum(){
	char c; int ans = 0; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = false; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
bool cmp(int a, int b){return a > b;}
int n, a[150], ai, cnt, sum, max1, tmp, len, vis[150];
int dfs(int now, int pos, int d){
	if (d == tmp) return 1;
	if (now == 0) if (dfs(len, 1, d + 1)) return 1;
	for (int i = pos; i <= cnt; i++){
		if (vis[i] == 0 && a[i] <= now){
			vis[i] = 1;
			if (dfs(now - a[i], i + 1, d)) return 1;
			vis[i] = 0;
			if (now == a[i] || now == len) break;
			while (a[i + 1] == a[i]) i++;
		}
	}
	return 0;
}
int main(){
	n = getnum();
	for (int i = 1; i <= n; i++){
		ai = getnum();
		if (ai <= 50) a[++cnt] = ai, sum += ai;
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = a[1]; i <= sum; i++){
		if (sum % i == 0){
			tmp = sum / i;
			len = i;
			if (dfs(len, 1, 0) == 1){
				cout << len;
				return 0;
			}
		}
	}
}
