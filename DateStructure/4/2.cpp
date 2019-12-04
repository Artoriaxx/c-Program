#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 10;
struct node {
	char id;
	int val;
	bool operator < (const node &b) const {
		return val > b.val;
	}
	node(int id = 0, int val = 0): id(id), val(val) {}
} weight[N];
char charset[N];
struct huftree {
	char ch;
	int l, r;
	int fa;
} Htree[N];
int n;
map<string, char> mp1;
map<char, string> mp2;
void build() {
	priority_queue<node> q;
	for (int i = 1; i <= n; i++) {
		q.push(weight[i]);
	}
	for (int i = 1; i <= n; i++) {
		Htree[i].ch = charset[i];
		Htree[i].l = Htree[i].r = Htree[i].fa = -1;
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		Htree[i].l = Htree[i].r = Htree[i].fa = -1;
	}
	int cnt = 1;
	while (!q.empty()) {
		node a = q.top(); q.pop();
		bool flag = false;
		node b;
		if (!q.empty()) {
			flag = true;
			b = q.top(); q.pop();
		}
		if (flag) {
			Htree[a.id].fa = Htree[b.id].fa = n + cnt;
			Htree[n + cnt].l = a.id;
			Htree[n + cnt].r = b.id;
			q.push(node(n + cnt, a.val + b.val));
		}
		else {
			break;
		}
		cnt++;
	}
	
	for (int i = 1; i <= n; i++) {
		string ss = "";
		int tmp = i;
		while (Htree[tmp].fa != -1) {
			int fa = Htree[tmp].fa;
			if (tmp == Htree[fa].l) ss = ss + "0";
			else ss = ss + "1";
			tmp = fa;
		}
		reverse(ss.begin(), ss.end());
		mp1[ss] = charset[i];
		mp2[charset[i]] = ss;
	}
}
void init() {
	FILE *fp;
	fp = fopen("in.txt", "r");

	fscanf(fp, "%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		fscanf(fp, "%s%d", &charset[i], &weight[i].val);
		weight[i].id = i;
	}
	build();
	fclose(fp);
}
char text[N];
void encode() {
	FILE *fpin, *fpout;
	fpin = fopen("ToBeTran.txt", "r");
	fpout = fopen("CodeFile.txt", "w");
	fscanf(fpin, "%s", text);
	int len = strlen(text);
	for (int i = 0; i < len; i++) {
		fprintf(fpout, "%s", mp2[text[i]].c_str());
	}
	fclose(fpin);
	fclose(fpout);
}
void decode() {
	FILE *fpin, *fpout;
	fpin = fopen("CodeFile.txt", "r");
	fpout = fopen("CodePrint.txt", "w");
	memset(text, 0, sizeof(text));
	fscanf(fpin, "%s", text);
	int len = strlen(text);
	string ss = "";
	for (int i = 0; i < len; i++) {
		ss = ss + text[i];
		if (mp1.count(ss) != 0) {
			fprintf(fpout, "%c", mp1[ss]);
			ss = "";
		}
	}
	fclose(fpin);
	fclose(fpout);
}
int main() {
	char q[2];
	while (scanf("%s", q) && q[0] != 'B') {
		switch(q[0]) {
			case 'I': init(); break;
			case 'E': encode(); break;
			case 'D': decode(); break;
		} 
	}
	return 0;
}