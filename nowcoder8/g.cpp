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

const int N = 300;
struct node {
    int s[4];
    node() {
        s[0] = s[1] = s[2] = s[3] = 0;
    }
    bool operator == (const node &b) const {
        for (int i = 0; i < 4; i++) {
            if (s[i] != b.s[i]) return 0;
        }
        return 1;
    }
    bool operator < (const node &b) const {
        for (int i = 0; i < 4; i++) {
            if (s[i] == b.s[i]) continue;
            return s[i] < b.s[i];
        }
        return 0;
    }
} c[N];
char tmp[1000];
char t[4][3][10] = {
    {"one", "two", "three"},
    {"diamond", "squiggle", "oval"},
    {"solid", "striped", "open"},
    {"red", "green", "purple"}
};
void init(int pos, char s[]) {
    int n = strlen(s);
    int cnt = -1;
    int len = 0;
    char tt[100];
    for (int i = 0; i < n; i++) {
        if (s[i] == '[') cnt++;
        else if (s[i] == ']') {
            tt[len] = '\0';
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (strcmp(tt, t[i][j]) == 0) {
                        c[pos].s[cnt] = i * 3 + j + 1;
                    }
                }
            }
            len = 0;
        }
        else tt[len++] = s[i];
    }
}

int get(int s, int t, int type) {
    if (s == 0 || t == 0) return 100;
    if (s == t) return s;
    for (int i = type * 3 + 1; i < (type + 1) * 3 + 1; i++) {
        if (i != s && i != t) return i;
    }
}
vector<int> num[N];
map<node, int> mp;
int ans;
bool fff = false;
int 
void dfs(node x, int dep) {
    if (dep >= 4) {
        if (mp.count(x)) {
            ans = mp[x];
            fff = true;
        }
        return;
    }
    int y = x.s[dep];
    if (y == 100) {
        for (int i = dep * 3 + 1; i < (dep + 1) * 3 + 1; i++) {
            x.s[dep] = i;
            dfs(x, dep + 1);
        }
        x.s[dep] = 0;
        dfs(x, dep + 1);
        x.s[dep] = 100;
    }
    x.s[dep] = 0;
    dfs(x, dep + 1);
    x.s[dep] = y;
    dfs(x, dep + 1);
}
int main() {
    int tc; scanf("%d", &tc);
    int cse = 0;
    while (tc--) {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < N; i++) num[i].clear();
        int n; scanf("%d", &n);
        getchar();
        mp.clear();
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin.getline(tmp, 1000);
            init(i, tmp);
            if (!mp.count(c[i])) mp[c[i]] = ++cnt;
            num[mp[c[i]]].push_back(i);
            //printf("%d %d %d %d\n", c[i].s[0], c[i].s[1], c[i].s[2], c[i].s[3]);
        }
        bool flag = false;
        printf("Case %d:", ++cse);
        for (int i = 1; i <= cnt; i++) {
            if (num[i].size() >= 3) {
                for (int j = 0; j < 3; j++) {
                    printf(" %d", num[i][j]);
                }
                puts("");
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (int i = 1; i <= n; i++) {
            if (flag) break;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                node nx;
                for (int k = 0; k < 4; k++) {
                    nx.s[k] = get(c[i].s[k], c[j].s[k], k);
                }
                fff = false;
                dfs(nx, 0);
                if (fff) {
                    printf(" %d %d %d\n", i, j, num[ans][0]);
                    flag = true;
                    break;
                } 
                
            }
        }
        if (!flag) {
            puts(" -1");
        }
    }
    return 0;
}
