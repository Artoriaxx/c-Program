/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2018-12-18 13:40:49
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-08 17:35:41
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
	srand(time(NULL));
	int t = 10;
	printf("%d\n", t);
	while (t--) {
		int n = rand() % 10 + 1;
		for (int i = 1; i <= n; i++) {
			int x = rand() % 2;
			if (x == 1) putchar('x');
			else putchar('l');
		}
		puts("");

	}
	return 0;
}