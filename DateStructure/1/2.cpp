#include <bits/stdc++.h>
#define N 105
using namespace std;
struct POS {
    int x, y;
};
struct node {
	char name[N];
    POS point;
	node* next;
};
node* phead;
void create() {
	phead = (node*)malloc(sizeof(node));
	int n;
	printf("Enter the initial list size\n");
	scanf("%d", &n);
	node* p1 = phead;
	for (int i = 1; i <= n; i++) {
		node* tmp = (node*)malloc(sizeof(node));
		printf("Enter the city name\n");
		scanf("%s", tmp->name);
		printf("Enter the city coordinate\n");
        scanf("%d%d", &tmp->point.x, &tmp->point.y);
		p1->next = tmp;
		p1 = p1->next;
	}
	p1->next = NULL;
	return;
}
void insert(int pos, char name[], POS point) {
	node* p1 = phead;
	int now = 0;
	while (p1->next != NULL) {
		if (++now == pos) break;
		p1 = p1->next;
	}
	node* tmp = (node*)malloc(sizeof(node));
	strcpy(tmp->name, name);
    tmp->point = point;
	tmp->next = p1->next;
	p1->next = tmp;
	return;
}
void del(char name[]) {
	node* p1 = phead, * pre;
    bool flag = false;
	while (p1->next != NULL) {
		pre = p1;
		p1 = p1->next;
		if (strcmp(p1->name, name) == 0) {
            flag = true;
            break;
        }  
	}
	if (flag) pre->next = p1->next;
    else printf("Not Found\n");
}
void find(char name[]) {
	node* p1 = phead;
	int now = 0;
	while (p1->next != NULL) {
		p1 = p1->next;
		now++;
		if (strcmp(p1->name, name) == 0) {
			printf("City %s is located in %d, %d\n", name, p1->point.x, p1->point.y);
			return;
		}
	}
	printf("Not Found\n");
}
void update(char name[], POS point) {
	node* p1 = phead;
	while (p1->next != NULL) {
		p1 = p1->next;
		if (strcmp(p1->name, name) == 0) {
			p1->point = point;
			return;
		}
	}
}
void print() {
	node* p1 = phead;
	while (p1->next != NULL) {
		p1 = p1->next;
		printf("City %s is located in %d, %d\n", p1->name, p1->point.x, p1->point.y);
	}
	printf("\n");
}
int dis(POS a, POS b) {
	return (b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x);
}
void getdis(POS x, int dist) {
	node* p1 = phead;
	while (p1->next != NULL) {
		p1 = p1->next;
		if (dis(x, p1->point) <= dist * dist) {
			printf("%s\n", p1->name);
		}
	}
	return;
}
char name[N];
int main() {
	freopen("2.txt", "r", stdin);
	//freopen("out2.txt", "w", stdout);
	create();
	bool flag = true;
	while (1) {
		if (!flag) break;
		char ch[2];
		printf("Enter the operation code\n");
		scanf("%s", ch);
		int pos;
        POS point;
		switch (ch[0]) {
		case 'I':
			scanf("%d%s%d%d", &pos, name, &point.x, &point.y);//在位置pos插入城市名为name,坐标为point的节点,如果pos大于链表长度，则插入到最后
			insert(pos, name, point);
			break;
		case 'D':
			scanf("%s", name);//删除城市名为name的节点，找不到输出Not Found
			del(name);
			break;
		case 'F':
			scanf("%s", name);//查找城市名为name的坐标
			find(name);
			break;
		case 'U':
			scanf("%s%d%d", name, &point.x, &point.y);//将城市名为name的节点坐标修改为point
			update(name, point);
			break;
		case 'P':
			print();//打印链表
			break;
		case 'B':
			flag = false;
			break;
		case 'G':
			int dist;
			scanf("%d%d%d", &point.x, &point.y, &dist);
			getdis(point, dist);
			break;
		}
	}
	return 0;
}