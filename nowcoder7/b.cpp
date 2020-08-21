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

const int N = 250;
struct node {
    int to[30][30];
    node() {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) to[i][j] = -1;
        }
    } 
} ob[30];
char l[N][10], r[N][10], e[10];
bool isupper(char c) {
    return c >= 'A' && c <= 'Z';
}
int mp[30][30];
void merge(int a[], int b[]) {
    for (int j = 0; j < 26; j++) {
        a[j] = max(a[j], b[j]);
    }
}
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s%s%s", l[i], e, r[i]);
    int t = 200;
    while (t--) {
        for (int i = 1; i <= n; i++) {
            int len1 = strlen(l[i]);
            int len2 = strlen(r[i]);
            if (len1 == 1 && len2 == 1) {
                if (isupper(r[i][0])) {
                    merge(mp[l[i][0] - 'A'], mp[r[i][0] - 'A']);
                }
                else {
                    mp[l[i][0] - 'A'][r[i][0] - 'a'] = 1;
                }
            }
            else if (len1 == 3 && len2 == 1) {
                int x = l[i][0] - 'A';
                for (int j = 0; j < 26; j++) {
                    if (mp[x][j] == 1) {
                        merge(ob[j].to[l[i][2] - 'a'], mp[r[i][0] - 'A']);
                    }
                }
            }
            else {
                int x = r[i][0] - 'A';
                for (int j = 0; j < 26; j++) {
                    if (mp[x][j] == 1) {
                        merge(mp[l[i][0] - 'A'], ob[j].to[r[i][2] - 'a']);
                    }
                }
                
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%c: ", 'A' + i);
        for (int j = 0; j < 26; j++) {
            if (mp[i][j] == 1) putchar('a' + j);
        }
        puts("");
    }
    return 0;
}
