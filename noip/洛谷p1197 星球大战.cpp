#include<bits/stdc++.h>
#define re register int
#define maxm 400050
using namespace std;
inline int getnum(){
    int ans = 0; bool flag = false; char c;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') flag = true; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * (flag ? -1 : 1);
}
int n, m, k;
vector<int> G[maxm];
int x[maxm];
int use[maxm];
int ans[maxm];
int f[maxm];
inline void init(){
    for (int i = 0; i < n; i++){
        f[i] = i;
    }
}
inline int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main(){
    n = getnum(), m = getnum();
    for (re i = 1; i <= m; i++){
        int a = getnum(), b = getnum();
        G[a].push_back(b), G[b].push_back(a);
    }
    k = getnum();
    for (re i = 1; i <= k; i++){
        x[i] = getnum();
        use[x[i]] = 1;
    }
    int block = n - k;
    init();
    for (re i = 0; i < n; i++){
        for (re j = 0; j < G[i].size(); j++){
            int v = G[i][j];
            if (!use[i] && !use[v] && find(v) != find(i)){
                block--;
                f[find(v)] = find(i);
            }
        }
    }
    int cnt = 0;
    ans[++cnt] = block;
    for (re i = k; i >= 1; i--){
        block++;
        use[x[i]] = 0;
        for (re j = 0; j < G[x[i]].size(); j++){
            int v = G[x[i]][j];
            if (!use[x[i]] && !use[v] && find(x[i]) != find(v)){
                block--;
                f[find(v)] = find(x[i]);
            }
        }
        ans[++cnt] = block;
    }
    for (re i = cnt; i >= 1; i--){
        printf("%d\n", ans[i]);
    }
    return 0;
}
