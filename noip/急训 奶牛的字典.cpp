#include<bits/stdc++.h>
#define p 163
using namespace std;
int w, l;
char s1[305];
char s[605][30];
int f[350];
inline int same(int x, int y){
	int sum = 0, li = x, lj = 1;
	int lk = strlen(s[y] + 1);
	while (li <= l){
		while (s1[li] != s[y][lj] && li <= l) li++, sum++;
		if (li > l) return -1;
		if (lj == lk) return sum;
		li++, lj++;
	}
	return -1;
}
int main(){
	scanf("%d%d", &w, &l);
	scanf("%s", s1 + 1);
	for (int i = 1; i <= w; i++){
		scanf("%s", s[i] + 1);
	}
	for (int i = l; i >= 1; i--){
		f[i] = f[i + 1] + 1;
		for (int j = 1; j <= w; j++){
			int tmp = same(i, j);
			int li = strlen(s[j] + 1);
			if (tmp != -1) f[i] = min(f[i], f[i + li + tmp] + tmp);
		}
	}
	printf("%d", f[1]);
	return 0;
}
