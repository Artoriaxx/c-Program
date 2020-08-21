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
struct node {
    int x, y, len;
};
char a[N];
int main() {
    int t; scanf("%d", &t);
    int cse = 0;
    while (t--) {
        node s;
        scanf("%d%d", &s.x, &s.y);
        s.len = 0;
        scanf("%s", a + 1);
        int len = strlen(a + 1);
        vector<node> path;
        path.push_back(s);
        for (int i = 1; i <= len; i++) {
            s.len++;
            if (a[i] == 'S') s.y -= 1;
            if (a[i] == 'N') s.y += 1;
            if (a[i] == 'E') s.x += 1;
            if (a[i] == 'W') s.x -= 1;
            path.push_back(s);
        }
        int ans = 1e9;
        bool flag = false;
        for (int i = 0; i < path.size(); i++) {
            int dis = abs(path[i].x) + abs(path[i].y);
            if (dis <= path[i].len) {
                ans = min(ans, path[i].len);
                flag = true;
            }
        }
        if (!flag) printf("Case #%d: %s\n", ++cse, "IMPOSSIBLE");
        else printf("Case #%d: %d\n", ++cse, ans);
    }
    return 0;
}
