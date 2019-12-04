#include <bits/stdc++.h>
#define lson (root << 1)
#define rson (root << 1 | 1)
using namespace std;
const int N = 1e7 + 10;
char ch[N];
struct tree {
    int l, r;
    char val;
} t[N];
int cnt, len;
void build(int root) {
    if (cnt < len) t[root].val = ch[cnt++];
    else return;
    if (t[root].val != ' ' && cnt < len) t[root].l = lson, build(lson);
    if (t[root].val != ' ' && cnt < len) t[root].r = rson, build(rson);
}
void dfs1(int root) {
    if (t[root].val != ' ' && t[root].val != '\0') {
        printf("%c", t[root].val);
        dfs1(t[root].l);
        dfs1(t[root].r);
    }
}
void dfs2(int root) {
    if (t[root].val != ' ' && t[root].val != '\0') {
        dfs2(t[root].l);
        printf("%c", t[root].val);
        dfs2(t[root].r);
    }
}
void dfs3(int root) {
    if (t[root].val != ' ' && t[root].val != '\0') {
        dfs3(t[root].l);
        dfs3(t[root].r);
        printf("%c", t[root].val);
    }
}
int dep[N];
int dmax = 0;
void getdep(int root) { 
	dmax = max(dmax, dep[root]);
    if (t[lson].val != ' ') dep[lson] = dep[root] + 1, getdep(lson);
    if (t[rson].val != ' ') dep[rson] = dep[root] + 1, getdep(rson);
}
bool flag = true;
void printHelp(int root, string ss) {
	if(t[root].val == ' ')   return;  
	if (!flag) {
		ss += "  ";
	}
	flag = false;
	printHelp(t[root].r,ss);  
	cout << ss << t[root].val << '\n';  
	printHelp(t[root].l,ss); 

}
int main() {
    freopen("5.txt", "r", stdin);
    cin.getline(ch, N);
    len = strlen(ch);
    cnt = 0;
    build(1);
    printf("DLR:");
    dfs1(1);
    printf("\nLDR:");
    dfs2(1);
    printf("\nLRD:");
    dfs3(1);
    printf("\n");
    dep[1] = 1;
    getdep(1);
    string s = "";
    printHelp(1, s);
    return 0;
}