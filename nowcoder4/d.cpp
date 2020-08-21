#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
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
char s[N];
int n;
int ans;
int cmx[N], cmn[N], cnow[N];
bool cmp(int a[], int b[], int len) {
    for (int i = 1; i <= len; i++) if (a[i] != b[i]) return a[i] > b[i];
    return 0;
}
void copy(int a[], int b[], int len) {
    for (int i = 1; i <= len; i++) a[i] = b[i];
}
void check(int i) {
    for (int j = 1; j <= i; j++) cmn[j] = 9, cmx[j] = 0;
    for (int j = 1; j <= n; j++) {
        if (j % i == 1 && s[j] == '0') return;
        cnow[j % i == 0 ? i : j % i] = s[j] - '0';
        if (j % i == 0) {
            if (cmp(cnow, cmx, i)) copy(cmx, cnow, i);
            if (cmp(cmn, cnow, i)) copy(cmn, cnow, i); 
        }
    }
    int mni = 9;
    for (int j = i; j >= 1; j--) {
        int t = cmx[j] - cmn[j];
        if (t < 0) cmx[j - 1]--, t += 10;
        if (j == i) mni = t;
        else if (t > 0) return;
    }
    ans = min(ans, mni);
}
int find() {
    for (int now = 1; now <= n; now++) {
        if (s[now] == '1') {
            int l = now;
            while (now < n && s[now + 1] == '0') now++;
            if (now < n && s[now + 1] != '9') now++;
            return now - l + 1;
        }
    }
    return -1;
}
int calc(int len) {
    int n1 = -1, n9 = 10;
    for (int now = 1; now <= n; now++) {
        int l = now;
        if (s[now] == '1') {
            while (now < n && s[now + 1] == '0') now++;
            if (now < n && now - l + 1 < len && s[now + 1] != '9') now++;
            if (now - l + 1 != len) return 9;
            n1 = max(n1, s[now] - '0');
        }
        else {
            now--;
            while (now < n && s[now + 1] == '9' && now - l + 1 < len - 1) now++;
            if (now < n && now - l + 1 < len - 1) now++;
            if (now - l + 1 != len - 1) return 9;
            n9 = min(n9, s[now] - '0');
        }
    }
    if (n9 == 10 || n1 == -1) return 9;
    return n1 + 10 - n9;
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        int mxi = 0, mni = 1e9;
        for (int i = 1; i <= n; i++) {
            mxi = max(mxi, s[i] - '0');
            mni = min(mni, s[i] - '0');
        }
        ans = mxi - mni;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) check(i);
        }
        int len = find();
        if (len > 1) ans = min(ans, calc(len));
        if (len > 2) ans = min(ans, calc(len - 1));
        printf("%d\n", ans);
    }
    return 0;
}
