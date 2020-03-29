#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
char ss[N * 2];
int p[N * 2];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);
        //manacher
        ss[0] = '$', ss[1] = '#';
        int len = 1;
        for (int i = 0; i < n; i++) ss[++len] = s[i], ss[++len] = '#';
        ss[++len] = '^';
        for (int i = 1; i < len; i++) p[i] = 0;
        int c = 0, r = 0;//c: 回文串中心 r: 右边界
        for(int i = 1; i < len; i++) {
            int x = 2 * c - i;//关于c对称的坐标
            if (r > i) {
                p[i] = min(r - i, p[x]);//如果i处于一个回文串中,那么他的长度等于min(关于回文串中心对称的那个点的p,右边界到这个点的串长度)
            }
            else p[i] = 0;
            while (ss[i + p[i] + 1] == ss[i - p[i] - 1]) ++p[i];//进行拓展,由于用之前的回文串更新了一次p,从而复杂度不会爆炸
            if (i + p[i] > r) {//更新右边界和中心
                c = i;
                r = i + p[i];
            }
        }
        
        int d = 0;
        while (s[d] == s[n - d - 1] && d < n) d++;
        int mx = 0, ansl, ansr, m;
        for (int i = 1; i < len; i++) {
            int st = (i - p[i]) / 2, ed = (i + p[i]) / 2 - 1;
            int x = min(st - 1, n - ed - 1);
            if (x <= d && 2 * x + p[i] > mx) {
                mx = 2 * x + p[i];
                m = x;
                ansl = st;
                ansr = ed;
            }
        }

        for (int i = 0; i <= m; i++) putchar(s[i]);
        for (int i = ansl; i <= ansr; i++) putchar(s[i]);
        for (int i = n - m; i < n; i++) putchar(s[i]);
        puts("");
    }
    return 0;
}