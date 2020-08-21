/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-11 08:47:13
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-11 08:49:13
 */
/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-11 08:47:13
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-11 08:47:13
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ios {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline ios & operator >> (_Tp&x) {
        static char c11, boo;
        for(c11 = read(),boo = 0; !isdigit(c11); c11 = read()) {
            if(c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for(x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
} in;

const int N = 1e4 + 50;
int a[N];
char b[N][10];
int vis[100];
vector<char> ap;
int ans[100];
char ans2[100];
bool flag;
void dfs(int n) {
    if (flag) return;
    if (n >= 10) {
        flag = true;
        for (int i = 1; i <= 1e4; i++) {
            int len = strlen(b[i] + 1);
            int now = 0;
            for (int j = 1; j <= len; j++) now = now * 10 + ans[b[i][j] - 'A'];
            if (now <= a[i]);
            else {
                flag = false;
                break;
            }
        }
        return;
    }
    for (int i = 0; i < ap.size(); i++) {
        if (flag) return;
        if (!vis[i]) {
            if (flag) return;
            vis[i] = 1;
            ans[ap[i] - 'A'] = n;
            ans2[n] = ap[i];
            dfs(n + 1);
            if (flag) return;
            ans[ap[i] - 'A'] = 1e7;
            ans2[n] = '0';
            vis[i] = 0;
        }
        if (flag) return;
    }
}

int zero[30];
int main() {
    //freopen("sample.in.txt", "r", stdin);
    int t; scanf("%d", &t);
    int cse = 0;
    while (t--) {
        int u; scanf("%d", &u);
        for (int i = 0; i < 26; i++) vis[i] = 0;
        for (int i = 1; i <= 1e4; i++) scanf("%d %s", &a[i], b[i] + 1);
        for (int i = 0; i < 50; i++) ans[i] = 1e7;
        for (int i = 0; i < 50; i++) zero[i] = 0;
        ap.clear();
        int x = 1;
        bool f1 = false, f2 = false;
        for (int i = 1; i <= 1e4; i++) {
            int len = strlen(b[i] + 1);
            for (int j = 1; j <= len; j++) {
                if (!vis[b[i][j] - 'A']) {
                    vis[b[i][j] - 'A'] = 1;
                    ap.push_back(b[i][j]);
                }
            }
            zero[b[i][1] - 'A']++;
            if (a[i] == 1) {
                ans2[1] = b[i][1];
                ans[b[i][1] - 'A'] = 1;
                if (!f1) x++, f1 = true;
            }
            if (a[i] == 2) {
                if (b[i][1] != ans2[1]) {
                    ans2[2] = b[i][1];
                    ans[b[i][1] - 'A'] = 2;
                    if (!f2) x++, f2 = true;
                }
            }
        }
        for (int i = 0; i < ap.size(); i++) {
            if (zero[ap[i] - 'A'] == 0) {
                ans2[0] = ap[i];
                ans[ap[i] - 'A'] = 0;
                break;
            }
        }
        for (int i = 0; i < 26; i++) vis[i] = 0;
        for (int i = 0; i < ap.size(); i++) {
            for (int j = 0; j < x; j++) {
                if (ap[i] == ans2[j]) {
                    vis[i] = 1;
                }
            }
            
        }
        flag = false;
        dfs(x);
        printf("Case #%d: ", ++cse);
        for (int i = 0; i < 10; i++) printf("%c", ans2[i]);
        puts("");
    }
    return 0;
}
