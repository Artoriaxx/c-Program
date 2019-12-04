#include <bits/stdc++.h>
using namespace std;
struct node {
	int val;
	node* next, * pre;
};
node* p1head, * p2head, * reshead;
node* p1tail, * p2tail, * restail;
bool flag1, flag2;
void inserthead(node* p, int val) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->val = val;
	tmp->pre = p;
	p->next = tmp;
}
void inserttail(node* p, int val) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->val = val;
	tmp->next = p;
	p->pre = tmp;
}
void create() {
	p1head = (node*)malloc(sizeof(node));
	p2head = (node*)malloc(sizeof(node));
	reshead = (node*)malloc(sizeof(node));
	p1tail = (node*)malloc(sizeof(node));
	p2tail = (node*)malloc(sizeof(node));
	restail = (node*)malloc(sizeof(node));
}
void init() {
	char c;
	int ans = 0;
	node* p1 = p1head;
	node* p2 = p2head;
	while ((c = getchar()) != ' ') {
		if (c == '-') { flag1 = true; continue; }
		else if (c != ',') ans = ans * 10 + c - '0';
		else {
			inserthead(p1, ans);
			p1 = p1->next;
			ans = 0;
		}
	}
	inserthead(p1, ans);
	p1->next->next = NULL;
	p1tail = p1->next;
	ans = 0;
	while ((c = getchar()) != '\n') {
		if (c == '-') { flag2 = true; continue; }
		else if (c != ',') ans = ans * 10 + c - '0';
		else {
			inserthead(p2, ans);
			p2 = p2->next;
			ans = 0;
		}
	}
	inserthead(p2, ans);
	p2->next->next = NULL;
	p2tail = p2->next;
	ans = 0;
}
int getsize(node* p) {
	long long size = 0;
	while (p->next) {
		p = p->next;
		size++;
	}
	return size;
}
int cmp(node* p1, node* p2) {
	if (getsize(p1) == getsize(p2)) {
		while (p1->next && p2->next) {
			p1 = p1->next, p2 = p2->next;
			if (p1->val == p2->val) {
				continue;
			}
			else return p1->val > p2->val;
		}
		return -1;
	}
	else return getsize(p1) > getsize(p2);
}
bool flag;
void Myswap(node* p1, node* p2) {
	while (p1->next && p2->next) {
		p1 = p1->next, p2 = p2->next;
		swap(p1->val, p2->val);
	}
}
int isok = 1;
void calc() {
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));
	node* p3 = (node*)malloc(sizeof(node));
	p1 = p1tail; p2 = p2tail; p3 = restail;
	if (!(flag1 ^ flag2)) {
		int rem = 0;
		while (p1 != p1head && p2 != p2head) {
			int ans = p1->val + p2->val + rem;
			rem = ans / 10000;
			ans = ans > 9999 ? ans % 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p1 = p1->pre; p2 = p2->pre;
		}
		while (p1 != p1head) {
			int ans = p1->val + rem;
			rem = ans / 10000;
			ans = ans > 9999 ? ans % 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p1 = p1->pre;
		}
		while (p2 != p2head) {
			int ans = p2->val + rem;
			rem = ans / 10000;
			ans = ans > 9999 ? ans % 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p2 = p2->pre;
		}
		if (rem) {
			inserttail(p3, rem);
			p3 = p3->pre; p2 = p2->pre;
		}
		reshead->next = p3;
		return;
	}
	if (cmp(p1head, p2head) == -1) {
		printf("0");
		isok = 0;
		return;
	}
	if (flag1 && !flag2) {
		if (cmp(p1head, p2head) > 0) flag = true;
		int rem = 0;
		if (flag) {
			Myswap(p1head, p2head);
		}
		while (p1 != p1head && p2 != p2head) {
			int ans = -p1->val + p2->val - rem;
			rem = ans < 0 ? 1 : 0;
			ans = ans < 0 ? ans + 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p1 = p1->pre; p2 = p2->pre;
		}
		while (p1 != p1head) {
			int ans = p1->val - rem;
			rem = ans < 0 ? 1 : 0;
			ans = ans < 0 ? ans + 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p1 = p1->pre;
		}
		while (p2 != p2head) {
			int ans = p2->val - rem;
			rem = ans < 0 ? 1 : 0;
			ans = ans < 0 ? ans + 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p2 = p2->pre;
		}
		reshead->next = p3;
		return;
	}
	if (!flag1 && flag2) {
		if (cmp(p1head, p2head) == 0) flag = true;
		int rem = 0;
		if (!flag) {
			Myswap(p1head, p2head);
		}
		while (p1 != p1head && p2 != p2head) {
			int ans = -p1->val + p2->val - rem;
			rem = ans < 0 ? 1 : 0;
			ans = ans < 0 ? ans + 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p1 = p1->pre; p2 = p2->pre;
		}
		while (p1 != p1head) {
			int ans = p1->val + rem;
			rem = ans < 0 ? 1 : 0;
			ans = ans < 0 ? ans + 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p1 = p1->pre;
		}
		while (p2 != p2head) {
			int ans = p2->val + rem;
			rem = ans < 0 ? 1 : 0;
			ans = ans < 0 ? ans + 10000 : ans;
			inserttail(p3, ans);
			p3 = p3->pre; p2 = p2->pre;
		}
		reshead->next = p3;
	}
}
void output() {
	node* p3 = (node*)malloc(sizeof(node));
	p3 = reshead;
	bool isfirst = true;
	if ((flag1 && flag2) || flag) printf("-");
	p3 = p3->next;
	if (p3->val) {
		isfirst = false;
		if (p3->next != restail) printf("%d,", p3->val);
		else {
			printf("%d", p3->val);
			return;
		}
	}
	while (p3->next != restail) {
		p3 = p3->next;
		if (p3->next != restail) {
			if (!isfirst) printf("%04d,", p3->val);
			else if (p3->val) printf("%d", p3->val), isfirst = false;
		}
		else break;
	}
	if (isfirst) printf("%d", p3->val);
	else printf("%04d", p3->val);
}
int main() {
	printf("Please enter two number, split by ,\n");
	create();
	init();
	calc();
	if (isok) output();
	return 0;
}