#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define re register int
using namespace std;
char s1[1000050], s2[1050];
int f[1500][1500];
int now[30];
int next[1000050][27];
int main(){
	scanf("%s%s", s1 + 1, s2 + 1);
	int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
	memset(now, inf, sizeof(now));
	for (re i = len1; i >= 0; i--){
		for (re j = 0; j < 26; j++) next[i][j] = now[j];//
		now[s1[i] - 'a'] = i;
	}
	for (re i = 0; i <= len2; i++){
		for (re j = 0; j <= len2; j++){
			f[i][j] = len1 + 1;
		}
	}
	f[0][0] = 0;
	for (re i = 1; i <= len2; i++){
		for (re j = 0; j <= i; j++){
			if (j == 0) f[i][j] = 0;
			else if (f[i - 1][j - 1] < len1){
				f[i][j] = min(f[i - 1][j], f[i][j]);
				f[i][j] = min(f[i][j], next[f[i - 1][j - 1]][s2[i] - 'a']);
			}
		}
	}
	int ans = 0;
	for (re i = 0; i <= len2; i++){
		if (f[len2][i] <= len1){
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
}
