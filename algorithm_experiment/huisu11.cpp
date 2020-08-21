#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
char s1[N], s2[N];
char tmp[N];
char ans[N];
int len;
void dfs(int cnt, int num1, int num2) {
    if (num1 > len) return;
    if (cnt > 2 * len) {
        if (num1 - num2 != 0) return;
        stack<char> s;
        int p1 = 0, p2 = 0;
        for (int i = 1; i <= len * 2; i++) {
            if (ans[i] == 'i') 
                s.push(s1[++p1]);
            else {
                tmp[++p2] = s.top();
                s.pop();
            }
        }
        tmp[++p2] = '\0';
        if (strcmp(tmp + 1, s2 + 1) == 0) {
            for (int i = 1; i <= len * 2; i++) {
                printf("%c ", ans[i]);
            }
            puts("");
        }
        return;
    }
    if (num1 - num2 > 0) {
        ans[cnt] = 'i';
        dfs(cnt + 1, num1 + 1, num2);
        ans[cnt] = 'o';
        dfs(cnt + 1, num1, num2 + 1);
    }
    else {
        ans[cnt] = 'i';
        dfs(cnt + 1, num1 + 1, num2);
    }
}
int main() {
    while (~scanf("%s%s", s1 + 1, s2 + 1)) {
        len = strlen(s1 + 1);
        printf("[\n");
        dfs(1, 0, 0);
        printf("]\n");
    }
    return 0;
}
