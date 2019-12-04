#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
struct tree {
	int fa;
	int ch[2];
	int val;
	int cnt;
} t[maxn];

inline int getnum() {
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}

inline void rotate(int x) {
	int y = t[x].fa;			  //X的父亲
	int z = t[y].fa;			  //X的祖父
	int k = (t[y].ch[1] == x);	  //X是Y的哪一个儿子 0是左儿子 1是右儿子
	t[z].ch[t[z].ch[1] == y] = x; //Z的原来的Y的位置变为X
	t[x].fa = z;				  //X的父亲变成Z
	t[y].ch[k] = t[x].ch[k ^ 1];  //X的与X原来在Y的相对的那个儿子变成Y的儿子
	t[t[x].ch[k ^ 1]].fa = y;	  //更新父节点
	t[x].ch[k ^ 1] = y;			  //X的 与X原来相对位置的儿子变成 Y
	t[y].fa = x;				  //更新父节点
}

inline void splay(int x, int goal) {            //将x旋转为goal的儿子，如果goal是0则旋转到根
	while(t[x].fa != goal) {             //一直旋转到x成为goal的儿子
		int y = t[x].fa; int z = t[y].fa;//父节点祖父节点
		if (z != goal)                   //如果Y不是根节点，则分为上面两类来旋转
			(t[z].ch[0] == y) ^ (t[y].ch[0] == x) ? rotate(x) : rotate(y);
			//X和Y分别是Y和Z的同一个儿子,先旋转Y再旋转X
			//X和Y分别是Y和Z不同的儿子,对X旋转两次
		rotate(x);                       //无论怎么样最后的一个操作都是旋转x
	}
	if (goal == 0) root = x;
}

inline int find(int x) {
	int u = root;
	if (!u) return;
	while (t[u].ch[x > t[u].val] && x != t[u].val)
		u = t[u].ch[x > t[u].val];
	splay(u, 0);
}

inline int insert(int x) {
	int u = root, fa = 0;
	while (u && t[u].val != x) {
		fa = u;
		u = t[u].ch[x > t[u].val];
	}
	if (u)
		t[u].cnt++;
	else {
		u = ++tot;
		if (fa)
			
	}

}
int main() {
	
	return 0;
}
