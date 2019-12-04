#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define db double
using namespace std;
int n, m, v, e;
inline int getnum(){
    int ans = 0; bool flag = false; char c;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') flag = true; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * (flag ? -1 : 1);
}
int op[2050][2050];
int a, b, c[2050], d[2050], w; double k[2050]; double f[2050][2050][2];
int main(){
    n = getnum(), m = getnum(), v = getnum(), e = getnum();
    for (register int i = 1; i <= n; i++) c[i] = getnum();
    for (register int i = 1; i <= n; i++) d[i] = getnum();
    for (register int i = 1; i <= n; i++) scanf("%lf", &k[i]);
    for (int i = 0; i <= v; i++){
        for (int j = 0; j <= v; j++){
            op[i][j] = inf;
        }
        op[i][i] = 0;
    }
    for (register int i = 1; i <= e; i++){
        a = getnum(), b = getnum(), w = getnum();
        if (a != b && w < op[a][b])
        op[a][b] = w, op[b][a] = w;
    }
    for (int ki = 1; ki <= v; ki++){
        for (int i = 1; i <= v; i++){
            for (int j = 1; j <= v; j++){
                op[i][j] = min(op[i][j], op[i][ki] + op[ki][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j <= m; j++) 
             f[i][j][0] = f[i][j][1] = inf; 
    f[1][1][1] = f[1][0][0] = 0.0;
    for (int i = 2; i <= n; i++){
        f[i][0][0] = f[i - 1][0][0] + db(op[c[i - 1]][c[i]]);
        for (register int j = 1; j <= min(m, i); j++){
            f[i][j][0] = min(f[i - 1][j][0] + db(op[c[i - 1]][c[i]]), f[i - 1][j][1] + k[i - 1] * db(op[d[i - 1]][c[i]]) + (1 - k[i - 1]) * db(op[c[i - 1]][c[i]]));
            f[i][j][1] = min(f[i - 1][j - 1][0] + k[i] * db(op[c[i - 1]][d[i]]) + (1 - k[i]) * db(op[c[i - 1]][c[i]]), f[i - 1][j - 1][1] + k[i - 1] * k[i] * db(op[d[i - 1]][d[i]]) + k[i - 1] * (1 - k[i]) * db(op[d[i - 1]][c[i]]) + k[i] * (1 - k[i - 1]) * db(op[c[i - 1]][d[i]]) + (1 - k[i]) * (1 - k[i - 1]) * db(op[c[i - 1]][c[i]])); 
        }
    }
    double ans = f[n][0][0];
    for (int i = 0; i <= m; i++){
        if (f[n][i][0] < ans) ans = f[n][i][0];
        if (f[n][i][1] < ans) ans = f[n][i][1];
    }
    printf("%.2lf", ans);
    return 0;
}
