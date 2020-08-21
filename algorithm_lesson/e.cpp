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
char s1[N], s2[N];
int main() {
    while (~scanf("%s %s", s1 + 1, s2 + 1)) {
        int len1 = strlen(s1 + 1);
        int len2 = strlen(s2 + 1);
        vector<int> pos[30];
        for (int i = 1; i <= len1; i++) pos[s1[i] - 'a'].push_back(i);
        bool flag = true;
        int now = 0, cnt = 1;
        for (int i = 1; i <= len2; i++) {
            int x = s2[i] - 'a';
            if (pos[x].size() == 0) {
                flag = false;
                break;
            }
            else {
                int l = 0, r = pos[x].size() - 1;
                int tmp = len1 + 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (pos[x][mid] > now) {
                        r = mid - 1;
                        tmp = min(tmp, pos[x][mid]);
                    }
                    else l = mid + 1;
                }
                if (tmp == len1 + 1) {
                    now = pos[x][0];
                    cnt++;
                }
                else now = tmp;
            }
        }
        if (!flag) puts("-1");
        else printf("%d\n", cnt);
    }
    return 0;
}
