#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef Artoriax
        return getchar();
    #endif
        const int LEN = 1 << 18 | 1;
        static char buf[LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)), s == t ? -1 : *s++;
    }
    inline READ & operator >> (char *s) {
        char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) *s++ = ch, ch = read(); *s = '\0';
        return *this;
    }
    inline READ & operator >> (string &s) {
        s = ""; char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) s += ch, ch = read();
        return *this;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        char ch, flag;
        for(ch = read(),flag = 0; !isdigit(ch) && ~ch; ch = read()) flag |= ch == '-';
        for(x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
        flag && (x = -x);
        return *this;
    }
} in;

const int N = 2e5 + 50;
#define pii pair<int, int>
int a[N];
int pos[N];
struct node {
    int a, b, c;
};
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) in >> a[i], sum += a[i];
        if (sum % n != 0) puts("-1");
        else {
            int x = sum / n;
            vector<node> ans; ans.clear();
            for (int i = 2; i <= n; i++) {
                int z = (i - a[i] % i) % i;
                if (a[1] >= z) {
                    ans.push_back(node{1, i, z});
                    a[1] -= z;
                    a[i] += z;
                }
                int cnt = a[i] / i;
                a[i] -= cnt * i;
                a[1] += cnt * i;
                ans.push_back(node{i, 1, cnt});
            }
            bool flag = true;
            for (int i = 2; i <= n; i++) {
                int val = x - a[i];
                if (val < 0) flag = false;
                ans.push_back(node{1, i, val});
                a[1] -= val;
                a[i] += val;
                if (a[1] < 0) flag = false; 
            }
            if (!flag) puts("-1");
            else {
                printf("%d\n", ans.size());
                for (auto now : ans) {
                    printf("%d %d %d\n", now.a, now.b, now.c);
                }
            }
            
        }
    }
    return 0;
}
