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

const int N = 550;
int a[N][N];
int n;
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
int work(int x, int y, int t) {
    vector<int> food;

    for (int i = -3; i <= 3; i++) {
        for (int j = -3; j <= 3; j++) {
            if (i == 0 && j == 0) continue;
            if (abs(i) + abs(j) <= 3 && check(x + i, y + j)) food.push_back(a[x + i][y + j]);
        }
    }
    sort(food.begin(), food.end());
    int p = food.size() - 1;
    int now = 1;
    int cnt = 0;
    int inc = a[x][y];
    int sum = 0;
    while (now < 9) {
        sum += inc;
        if (sum >= 8 * now * now) {
            now++;
            if (p >= 0) {
                inc += food[p];
                p--;
            }
        }
        cnt++;
    }
    return t + cnt;
}
int main() {
    int t; in >> t;
    while (t--) {
        int x, y; in >> n >> x >> y;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int mn = 1e9;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mn = min(mn, work(i, j, (abs(i - x) + abs(j - y) + 1) / 2));
            }
        }
        printf("%d\n", mn);
    }
    return 0;
}
