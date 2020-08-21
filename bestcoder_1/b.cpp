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
int score[] = {0, 0, 60, 62, 65, 67, 70, 75, 80, 85, 90, 95};
double point[] = {0, 0, 1.0, 1.7, 2.0, 2.3, 2.7, 3.0 , 3.3, 3.7, 4.0, 4.3}; 
int main() {
    int t; in >> t;
    while (t--) {
        int x; in >> x;
        double mx = 0;
        for (int i = 1; i <= 11; i++) {
            for (int j = 1; j <= 11; j++) {
                for (int k = 1; k <= 11; k++) {
                    int p1 = score[i], p2 = score[j], p3 = score[k];
                    int res = x - p1 - p2 - p3;
                    if (res < 0) continue;
                    double now = 0;
                    if (res <= 59);
                    else if (res <= 61) {
                        now += 1.0;
                    }
                    else if (res <= 64) {
                        now += 1.7;
                    }
                    else if (res <= 66) {
                        now += 2.0;
                    }
                    else if (res <= 69) {
                        now += 2.3;
                    }
                    else if (res <= 74) {
                        now += 2.7;
                    }
                    else if (res <= 79) {
                        now += 3.0;
                    }
                    else if (res <= 84) {
                        now += 3.3;
                    }
                    else if (res <= 89) {
                        now += 3.7;
                    }
                    else if (res <= 94) {
                        now += 4.0;
                    }
                    else {
                        now += 4.3;
                    }
                    now += point[i] + point[j] + point[k];
                    mx = max(mx, now);
                }
            }
        }
        printf("%.1f\n", mx);
    }
    return 0;
}
