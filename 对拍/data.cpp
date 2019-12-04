#include<bits/stdc++.h>
using namespace std;
int main() {
	srand(time(NULL));
	int t = rand() % 10;
	printf("%d\n", t);
	for (int i = 1; i <= t; i++) {
		printf("%d ", i);
		int n = rand() % 10 + 1;
		printf("%d\n", n);
		for (int i = 1; i <= n; i++) {
			int h = rand() % 13;
			int min = rand() % 60;
			printf("%d:%d\n", h, min);
		}
		for (int i = 1; i <= n; i++) {
			int flag = rand()%2;
			if (flag) cout << "+";
			else cout << "-";
			int h = rand() % 13;
			int min = rand() % 60;
			printf("%d:%d\n", h, min);
		}
	}

	return 0;
}