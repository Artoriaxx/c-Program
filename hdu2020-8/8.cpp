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
#define pii pair<int, int>
int a[N][N];
int vis[N][N];
int cx, cy;
int cen[N][N];
int dx[] = {-2, -1, 1, 2, 1, -1};
int dy[] = {0, 1, 1, 0, -1, -1};
int vis1[N][N];
int judge(int x, int y) {
    return cen[x][y];
}
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= 4 * n; i++) {
            for (int j = 1; j <= 2 * n; j++){
                a[i][j] = 0;
                vis[i][j] = 0;
                vis1[i][j] = 0;
            }
        }
        for (int i = 1; i <= 2 * n - 1; i++) {
            if (i <= n) {
                int cnt = n + i - 1;
                int st = n - i + 1;
                while (cnt--) {
                    a[st][i] = 1;
                    st += 2;
                }
            }
            else {
                int cnt = n + (2 * n - i) - 1;
                int st = n - (2 * n - i) + 1;
                while (cnt--) {
                    a[st][i] = 1;
                    st += 2;
                }
            }
        }

        cx = 2 * n - 1, cy = n;
        int nowx = 2 * n - 1, nowy = n;
        vis[nowx][nowy] = 1;
        //----------------------------------
        queue<pii> q;
        q.push(pii(nowx, nowy));
        vis1[nowx][nowy] = 1;
        cen[nowx][nowy] = 1;
        while (!q.empty()) {
            pii now = q.front(); q.pop();
            for (int i = 0; i < 6; i++) {
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if (vis1[nx][ny] || !a[nx][ny] || nx < 1 || ny < 1) continue;
                q.push(pii(nx, ny));
                cen[nx][ny] = cen[now.first][now.second] + 1;
                vis1[nx][ny] = 1;
            }
        }
        //-------------------------------
        if (n & 1) {
            for (int i = 1; i <= n / 2; i++) {
                int ne = i * 2;
                int wai = i * 2 + 1;
                nowx -= 1; nowy -= 1;
                vis[nowx][nowy] = 1;
                putchar('6');
                int cnt = 6 * ne - 6 + 6 * wai - 6 - 1;
                while (cnt) {
                    if (cnt == 0) break;
                    for (int dir = 0; dir < 6; dir++) {
                        int nx = nowx + dx[dir], ny = nowy + dy[dir];
                        if (vis[nx][ny] || a[nx][ny] != 1 || nx < 1 || ny < 1) continue;
                        if (judge(nx, ny) == wai) {
                            vis[nx][ny] = 1;
                            nowx = nx;
                            nowy = ny;
                            putchar('1' + dir);
                            cnt--;
                            break;
                        }
                    }
                    if (cnt == 0) break;
                    for (int dir = 0; dir < 6; dir++) {
                        int nx = nowx + dx[dir], ny = nowy + dy[dir];
                        if (vis[nx][ny] || a[nx][ny] != 1 || nx < 1 || ny < 1) continue;
                        if (judge(nx, ny) == wai) {
                            vis[nx][ny] = 1;
                            nowx = nx;
                            nowy = ny;
                            putchar('1' + dir);
                            cnt--;
                            break;
                        }
                    }
                    if (cnt == 0) break;
                    int tmpx = -1, tmpy = -1, ans = -1;
                    for (int dir = 0; dir < 6; dir++) {
                        int nx = nowx + dx[dir], ny = nowy + dy[dir];
                        if (vis[nx][ny] || a[nx][ny] != 1) continue;
                        if (judge(nx, ny) == ne) {
                            tmpx = nx, tmpy = ny;
                            ans = dir;
                        }
                    }
                    if (ans != -1) {
                        putchar('1' + ans);
                        vis[tmpx][tmpy] = 1;
                        nowx = tmpx, nowy = tmpy;
                        cnt--;
                    }
                }
            }
            puts("");
        }
        else {
            printf("532165");
            for (int i = 0; i < 6; i++) {
                vis[nowx + dx[i]][nowy + dy[i]] = 1;
            }
            nowx -= 1, nowy -= 1;
            vis[nowx][nowy] = 1;
            for (int i = 2; i <= n / 2; i++) {
                int ne = i * 2 - 1;
                int wai = i * 2;
                nowx -= 1; nowy -= 1;
                vis[nowx][nowy] = 1;
                putchar('6');
                int cnt = 6 * ne - 6 + 6 * wai - 6 - 1;
                while (cnt) {
                    //printf("%d\n", cnt);
                    if (cnt == 0) break;
                    for (int dir = 0; dir < 6; dir++) {
                        int nx = nowx + dx[dir], ny = nowy + dy[dir];
                        if (vis[nx][ny] || a[nx][ny] != 1 || nx < 1 || ny < 1) continue;
                        if (judge(nx, ny) == wai) {
                            vis[nx][ny] = 1;
                            nowx = nx;
                            nowy = ny;
                            putchar('1' + dir);
                            cnt--;
                            break;
                        }
                    }
                    if (cnt == 0) break;
                    for (int dir = 0; dir < 6; dir++) {
                        int nx = nowx + dx[dir], ny = nowy + dy[dir];
                        if (vis[nx][ny] || a[nx][ny] != 1 || nx < 1 || ny < 1) continue;
                        if (judge(nx, ny) == wai) {
                            vis[nx][ny] = 1;
                            nowx = nx;
                            nowy = ny;
                            putchar('1' + dir);
                            cnt--;
                            break;
                        }
                    }
                    if (cnt == 0) break;
                    int tmpx = -1, tmpy = -1, ans = -1;
                    for (int dir = 0; dir < 6; dir++) {
                        int nx = nowx + dx[dir], ny = nowy + dy[dir];
                        if (vis[nx][ny] || a[nx][ny] != 1) continue;
                        if (judge(nx, ny) == ne) {
                            tmpx = nx, tmpy = ny;
                            ans = dir;
                        }
                    }
                    if (ans != -1) {
                        putchar('1' + ans);
                        vis[tmpx][tmpy] = 1;
                        nowx = tmpx, nowy = tmpy;
                        cnt--;
                    }
                }
            }
            puts("");
        }
    }
    return 0;
}
//532165612421342353464356451562651261
//61242353464515626161242124235323534643464564515626562613161