#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
  inline char read() {
  #ifdef _WIN32
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
template<class T>
struct node {
  void f(T a, T b) {
    g(a, b);
  }
};
int main() {
  
  return 0;
}
