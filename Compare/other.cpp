/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2018-12-18 13:40:49
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-08 17:35:05
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 50;
int num[N], a[N];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		num[a[i]]++;
	}
	for (int i = 1; i <= (int)5e6; i++) {
		if (num[i] > 0) {
			k--;
			if (k == 0) {
				printf("%d\n", i);
				break;
			}
		}
	}
	if (k > 0) puts("-1");
	return 0;
}