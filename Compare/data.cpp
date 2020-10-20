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
vector< vector<int> > ans;
int main() {
	srand(time(NULL));
	int tot = 0;
	for (int i = 1; i <= 5; i++) {
		for (int a = 1; a <= i; a++) {
			for (int b = 1; b <= i; b++) {
				for (int c = 1; c <= i; c++) {
					tot++;
					vector<int> tmp;
					tmp.push_back(i);
					tmp.push_back(a);
					tmp.push_back(b);
					tmp.push_back(c);
					ans.push_back(tmp);
				}
			}
		}
	}
	printf("%d\n", tot);
	for (int i = 0; i < tot; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", ans[i][j]);
		}
		puts("");
	}
	return 0;
}