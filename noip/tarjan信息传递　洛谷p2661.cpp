#include<iostream>
#include<cstring>
#include<vector>
#define maxm 200005
#define maxn 200005
using namespace std;
int tmp, cnt;//tmp��¼ʱ�����cnt��¼�м���ǿ��ͨ����
struct node{
	int v, next;
}edge[maxm];
int num, head[maxn];
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
vector<int> umi[maxn];
int ans, ans1 = 0x3f3f3f3f;
int dfn[maxn], low[maxn], vis[maxn], stack[maxn], p, belong[maxn];
void tarjan(int u){
	int v;
	dfn[u] = ++tmp;//��¼ʱ��� 
	low[u] = tmp;
	vis[u] = true;//�Ƿ���ջ�� 
	stack[++p] = u;
	for (int i = head[u]; i; i = edge[i].next){
		v = edge[i].v;
		if (!dfn[v]){//���dfnû�б����¹�����ݹ���һ���� 
			tarjan(v);
			low[u] = min(low[u], low[v]);//������������ĵ�ָ���ܻ��ݵĵ��С������¸õ��low 
		}
		else if (vis[v] && dfn[v] < low[u]) low[u] = dfn[v];//
	}
	if (dfn[u] == low[u]){
		cnt++;
		ans = 0;
		do {
			v = stack[p--];
			vis[v] = false;
//			belong[v] = cnt;
//			umi[cnt].push_back(v);
			ans++;
		} while (v != u);
		if(ans > 1){
			ans1 = min(ans1, ans);
		}
	}
}
int main(){
	int n;
	cin >> n;
	int o;
	for (int i = 1; i <= n; i++){
		cin >> o;
		adde(i, o);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	cout<<ans1;
	return 0;
}
