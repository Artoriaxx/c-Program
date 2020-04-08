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
	int n = 1e5;
	int k = rand() % n + 1;
	printf("%d %d\n", n, k);
	for (int i = 1; i <= n; i++) {
		printf("%d ", (rand() % (n / 2)) + 1);
	}
	return 0;
}