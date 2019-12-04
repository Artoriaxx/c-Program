#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
int n, m;
vector<int> G[maxn];
inline int getnum(){
    int ans = 0; bool flag = false; char c;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') flag = true; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * (flag ? -1 : 1);
}
int a[maxn], b[maxn];
int val[maxn];
int dfn[maxn], low[maxn], tmp = 0, spe[maxn], sta[maxn], cnt = 0, vis[maxn], block, sumv[maxn];
void tarjan(int x){
    dfn[x] = low[x] = ++tmp;
    sta[++cnt] = x; vis[x] = 1;
    for (int i = 0; i < G[x].size(); i++){
        int v = G[x][i];
        if (!dfn[v]){
            tarjan(v);
            low[x] = min(low[v], low[x]);
        }
        else if (vis[v]) low[x] = min(low[x], dfn[v]);
    }
    if (low[x] == dfn[x]){
        ++block;
        int v;
        do {
            v = sta[cnt--];//��ջ 
            spe[v] = block;//Ⱦɫ 
            vis[v] = 0;//��ǲ���ջ�� 
            sumv[block] += val[v];//ͳ�ƺ� 
        } while (v != x);//��������ǿ��ͨ���� 
    }
}
int f[maxn];
void dp(int x){//���� 
    if (f[x]) return;
    f[x] = sumv[x];
    int maxl = 0;
    for (int i = 0; i < G[x].size(); i++){
        int v = G[x][i];
        if (!f[v]) dp(v);
        maxl = max(maxl, f[v]);
    }
    f[x] = max(f[x], f[x] + maxl);
}
int main(){
    n = getnum(), m = getnum();
    for (int i = 1; i <= n; i++){
        val[i] = getnum();
    }
    for (int i = 1; i <= m; i++){
        a[i] = getnum(), b[i] = getnum();
        G[a[i]].push_back(b[i]);
    }
    for (int i = 1; i <= n; i++){
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++){
        G[i].clear();
    }
    for (int i = 1; i <= m; i++){
        if (spe[a[i]] != spe[b[i]]){
            G[spe[a[i]]].push_back(spe[b[i]]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= block; i++){//�����ĵ��������˱仯 
        if (!f[i]){//��i������spe[i] 
            dp(i);
            ans = max(ans, f[i]);
        }
    }
    printf("%d", ans);
    system("pause");
    return 0;
}
