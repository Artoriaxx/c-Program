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

const int N = 4e5 + 50;
vector<int> G[N];
int check[N], matching[N];
bool dfs(int u, int tmp){
	for (int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if (check[v] != tmp){
			check[v] = tmp;
			if (matching[v] == -1 || dfs(matching[v], tmp)){
				matching[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        map<int, int> mp1, mp2;
        mp1.clear(), mp2.clear();
        int cntp = 0;
        for (int i = 1; i <= n; i++) {
            int t, x;
            in >> t >> x;
            if (!mp1.count(t + x)) {
                mp1[t + x] = ++cntp;
            }
            if (!mp2.count(t - x)) {
                mp2[t - x] = ++cntp;
            }
            int p1 = mp1[t + x];
            int p2 = mp2[t - x];
            G[i].push_back(p1 + n);
            G[i].push_back(p2 + n);
            G[p1 + n].push_back(i);
            G[p2 + n].push_back(i);
        }
        memset(check, 0, sizeof(check));
		memset(matching, -1, sizeof(matching));
        int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dfs(i, i)) {
				ans++;
			}
		}
        printf("%d\n", ans);
        for (int i = 1; i <= cntp + n + 1; i++) G[i].clear();
    }
    return 0;
}
