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

const int N = 2050;
string sta[N];
string mp[N];
string mp2[N];
int now[N];

int main() {
    ios::sync_with_stdio(false);
    mp[0] = "1110111";
    mp[1] = "0010010";
    mp[2] = "1011101";
    mp[3] = "1011011";
    mp[4] = "0111010";
    mp[5] = "1101011";
    mp[6] = "1101111";
    mp[7] = "1010010";
    mp[8] = "1111111";
    mp[9] = "1111011";
    mp2[0] = "0";
    mp2[1] = "1";
    mp2[2] = "2";
    mp2[3] = "3";
    mp2[4] = "4";
    mp2[5] = "5";
    mp2[6] = "6";
    mp2[7] = "7";
    mp2[8] = "8";
    mp2[9] = "9";
    int n, k;
    cin >> n >> k;
    
    return 0;
}
