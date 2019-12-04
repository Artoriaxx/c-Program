#include <bits/stdc++.h>
using namespace std;
struct node {
	int v;
	node* next;
};
node* phead;
void create() {
	phead = (node*)malloc(sizeof(node));
	int n;
	printf("Enter the initial list size:\n");
	scanf("%d", &n);
	node* p1 = phead;
	for (int i = 1; i <= n; i++) {
		node* tmp = (node*)malloc(sizeof(node));
		printf("Enter a number:\n");
		scanf("%d", &tmp->v);
		p1->next = tmp;
		p1 = p1->next;
	}
	p1->next = NULL;
	return;
}
void insert(int pos, int x) {
	node* p1 = phead;
	int now = 0;
	while (p1->next != NULL) {
		if (++now == pos) break;
		p1 = p1->next;
	}
	node* tmp = (node*)malloc(sizeof(node));
	tmp->v = x;
	tmp->next = p1->next;
	p1->next = tmp;
	return;
}
void del(int pos) {
	node* p1 = phead, * pre;
	if (pos == 1) {
		phead->next = p1->next;
		return;
	}
	int tmp = 0;
	while (p1->next != NULL) {
		pre = p1;
		p1 = p1->next;
		if (++tmp == pos) break;
	}
	pre->next = p1->next;
}
void find(int x) {
	node* p1 = phead;
	int now = 0;
	while (p1->next != NULL) {
		p1 = p1->next;
		now++;
		if (p1->v == x) {
			printf("Value x first appear at %d\n", now);
			return;
		}
	}
	printf("Not Found\n");
}
void update(int pos, int x) {
	node* p1 = phead;
	int now = 0;
	while (p1->next != NULL) {
		p1 = p1->next;
		now++;
		if (now == pos) {
			p1->v = x;
			return;
		}
	}
}
void print() {
	node* p1 = phead;
	while (p1->next != NULL) {
		p1 = p1->next;
		printf("%d ", p1->v);
	}
	printf("\n");
}
int main() {
	freopen("1.txt", "r", stdin);
	create();
	bool flag = true;
	while (1) {
		if (!flag) break;
		char ch[2];
		printf("Enter the operation code:\n");
		scanf("%s", ch);
		int pos, x;
		switch (ch[0]) {
		case 'I':
			scanf("%d%d", &pos, &x);//在位置pos插入值为x的节点,如果pos大于链表长度，则插入到最后
			insert(pos, x);
			break;
		case 'D':
			scanf("%d", &pos);//删除位置pos的节点,如果pos大于链表长度,则删除最后一个
			del(pos);
			break;
		case 'F':
			scanf("%d", &x);//查找值为x的数第一次出现的位置
			find(x);
			break;
		case 'U':
			scanf("%d%d", &pos, &x);//将位置为pos的节点值修改为x
			update(pos, x);
			break;
		case 'P':
			print();//打印链表
			break;
		case 'B':
			flag = false;
			break;
		}
	}
	return 0;
}