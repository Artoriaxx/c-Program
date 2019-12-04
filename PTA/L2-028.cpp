#include <bits/stdc++.h>
using namespace std;
int change(char s[]) {
    int len = strlen(s);
    int res = 0;
    if (s[0] == '-') {
        for (int i = 1; i < len; i++) {
            res = res * 10 + s[i] - '0';
        }
    }
    else {
        for (int i = 0; i < len; i++) {
            res = res * 10 + s[i] - '0';
        }
    }
    return res;
}
void output(int x) {
    if (x == 1) cout << "-";
}
int pic[1005][505], sex[1005][505];
char ch[100];
int k[1005];
double love[1005][1005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++) {
            scanf("%s", ch);
            pic[i][j] = change(ch);
            if (ch[0] == '-') sex[i][j] = 1;
        }
    }
    int sexa = 0, sexb = 0;
    int a, b;
    scanf("%s", ch);
    if (ch[0] == '-') sexa = 1;
    a = change(ch);
    scanf("%s", ch);
    if (ch[0] == '-') sexb = 1;
    b = change(ch);
    double maxa = 0, maxb = 0;
    for (int i = 1; i <= m; i++) {
        bool flaga = false, flagb = false;
        for (int j = 1; j <= k[i]; j++) {
            if (a == pic[i][j]) flaga = true;
            if (b == pic[i][j]) flagb = true;
        }
        if (flaga) {
            for (int j = 1; j <= k[i]; j++) {
                if (sex[i][j] != sexa) {
                    love[a][pic[i][j]] += 1.0 / (double)k[i];
                    maxa = max(maxa, love[a][pic[i][j]]);
                }
            }
        }
        if (flagb) {
            for (int j = 1; j <= k[i]; j++) {
                if (sex[i][j] != sexb) {
                    love[b][pic[i][j]] += 1.0 / (double)k[i];
                    maxb = max(maxb, love[b][pic[i][j]]);
                }
            }
        }
    }
    if (love[a][b] == maxa && love[b][a] == maxb) {
        output(sexa);
        cout << a << " ";
        output(sexb);
        cout << b << endl;
    }
    else {
        for (int i = 0; i <= 1000; i++) {
            if (maxa == love[a][i]) {
                output(sexa);
                cout << a << " ";
                output(!sexa);
                cout << i << endl;
            }
            
        }
        for (int i = 0; i <= 1000; i++) {
            if (maxb == love[b][i]) {
                output(sexb);
                cout << b << " ";
                output(!sexb);
                cout << i << endl;
            }
        }
    }
    return 0;
}