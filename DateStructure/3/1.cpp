#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n, m;
int next1[N];
char s[N], t[N][105];
void getNext(char t[]) {
	int i = 1, j = 0;
	next1[1] = 0;
    m = strlen(t + 1);
	while (i < m) {
		if (j == 0 || t[i] == t[j]) {
			i++; j++;
			next1[i] = j;
		}
		else j = next1[j];
	}
}
int kmp(char s[], char t[], int pos) {
	int i = pos, j = 1;
    n = strlen(s + 1);
    m = strlen(t + 1);
	while (i <= n && j <= m) {
		if (j == 0 || s[i] == t[j]) {
			i++; j++;
		}
		else j = next1[j];
	}
	if (j > m) return i - m;
	else return -1;
}
vector<int> ans[N];
int main() {
    freopen("4.txt", "r", stdin);
    int nn;
    scanf("%d", &nn);
    for (int i = 1; i <= nn; i++) {
        scanf("%s", t[i] + 1);
    }
    int len;
    scanf("%d", &len);
    int cnt = 0;
    getchar();
    while (len--) {
        cnt++;
        memset(s, 0, sizeof(s));
        cin.getline(s + 1, N);
        for (int i = 1; i <= nn; i++) {
            getNext(t[i]);
            int pos = kmp(s, t[i], 1);
            if (pos != -1) ans[i].push_back(cnt);
        }
    }
    for (int i = 1; i <= nn; i++) {
        printf("%s\n", t[i] + 1);
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}