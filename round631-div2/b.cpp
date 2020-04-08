/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-03 21:49:39
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-03 23:21:36
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

const int N = 2e5 + 50;
int a[N];
int val[N];
int maxx[N];
int cnt[N];
int maxx1[N];
int cnt1[N];
struct node {
    int x, y;
};
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        for (int i = 0; i <= n + 1; i++) {
            maxx[i] = val[i] = cnt[i] = 0;
            maxx1[i] = cnt1[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            maxx[i] = max(maxx[i - 1], a[i]);
            if (!val[a[i]]) cnt[i] = cnt[i - 1] + 1;
            val[a[i]] = 1;
        }
        for (int i = 0; i <= n + 1; i++) val[i] = 0;
        for (int i = n; i >= 1; i--) {
            maxx1[i] = max(maxx1[i + 1], a[i]);
            if (!val[a[i]]) cnt1[i] = cnt1[i + 1] + 1;
            val[a[i]] = 1;
        }
        vector<node> ans;
        ans.clear();
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == i && i == maxx[i] && cnt1[i + 1] == n - i && n - i == maxx1[i + 1]) {
                ans.push_back({i, n - i});
            }
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %d\n", ans[i].x, ans[i].y);
        }
        
    }
    return 0;
}