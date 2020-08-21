/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-08 21:13:56
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-09 10:40:38
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

const int N = 3050;
const int K = 3000050;
char s[N];
vector<int> ans[K];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    int cnt = 0;
    int mx = 0;
    while (1) {
        ++cnt;
        for (int i = 1; i <= n; i++) 
            if (s[i] == 'R' && s[i + 1] == 'L') ans[cnt].push_back(i), mx++;
        if (ans[cnt].empty()) {
            cnt--;
            break;
        }
        for (int i = 0; i < ans[cnt].size(); i++) swap(s[ans[cnt][i]], s[ans[cnt][i] + 1]);
    }
    if (cnt > k || k > mx) {
        puts("-1");
        return 0; 
    }
    int now = cnt;
    for (int i = k; i >= 1; i--) {
        if (ans[now].empty()) now--;
        if (!ans[i].empty()) break;
        ans[i].push_back(ans[now].back());
        ans[now].pop_back();
    } 
    for (int i = 1; i <= k; i++) {
        printf("%d", ans[i].size());
        for (auto x : ans[i]) printf(" %d", x);
        puts("");
    }
    return 0;
}
