//online 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100005;
struct io
{
	char op[1 << 26] , * s;
	//数组大小即读入数据量大小 
	io()
	{
		//一定注意在这里开文件 
		//使用fread时无法从console中输入，请使用文件读入 
//		freopen( "test.in" , "r" , stdin );
//		freopen( "test.out" , "w" , stdout );
		fread( s = op , 1 , 1 << 26 , stdin );
	}
	inline int read()
	{
		register int u = 0;
		while( * s < 48 ) s++;
		while( * s > 32 )
			u = u * 10 + * s++ - 48;
		return u;
	}
} ip;

#define getnum ip.read
//struct node{
//	int v, next;
//}edge[maxn];
//int head[maxn], num;
//inline void adde(int u, int v){
//	edge[++num].next = head[u];
//	edge[num].v = v;
//	head[u] = num;
//}

ll n, m, a, b;
ll cnt[maxn], ans, fa[maxn], point[maxn], caozuo[maxn], ans1, ji[maxn];
int main(){
//	freopen("sample6.in", "r", stdin);
//	freopen("sample6.out", "w", stdout);
	n = getnum(); m = getnum();
	for (int i = 2; i <= n; i++){
		a = getnum();
		cnt[a]++;
		fa[i] = a;
	}
	for(int i = 1; i <= n; i++){
		ji[i] = cnt[i];
	}
	for (int i = 1; i <= m; i++){
		b = getnum();
		if(b != 1){
			point[b] += 1;
			caozuo[b] += 1;
			point[fa[b]] += 1;
			cnt[fa[b]] += 1;
			cnt[fa[fa[b]]] += 1;
			ans = cnt[b] + point[b] + point[fa[b]] + caozuo[fa[b]] + caozuo[fa[fa[b]]];
			if(cnt[b]) cnt[b] += ji[b];
		}
		else{
			point[b] += 1;
			caozuo[b] += 1;
			ans = cnt[b] + point[b];
			if(cnt[b]) cnt[b] += ji[b];
		}
		ans1 += ans;
	}
	cout<<ans1;
	return 0;
}
/*
离线  
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <complex>
#include <iostream>
#define re register
#define inf 1e8
#define CD complex<double>
#define LL long long
#define pi 3.1415926535
using namespace std;

struct io
{
	char op[1 << 26] , * s;
	//数组大小即读入数据量大小 
	io()
	{
		//一定注意在这里开文件 
		//使用fread时无法从console中输入，请使用文件读入 
		//freopen( "sample6.in" , "r" , stdin );
		//freopen( "test.out" , "w" , stdout );
		fread( s = op , 1 , 1 << 26 , stdin );
	}
	inline int read()
	{
		register int u = 0;
		while( * s < 48 ) s++;
		while( * s > 32 )
			u = u * 10 + * s++ - 48;
		return u;
	}
} ip;
#define read ip.read


inline int read(){
	char c=getchar(),f=1;int v=0;
	for(;!isdigit(c);c=getchar())
		if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())
		v=(v<<1)+(v<<3)+c-'0';
	return v*f;
}
struct edge{
	int to,nt;
}e[200200];
int p[200200],coc=1;
int w[200200];
LL ans;
void add(int x,int y){
	e[coc].to=y;
	e[coc].nt=p[x];
	p[x]=coc++;
}
int main(){
	int n=read(),m=read();
	for(int i=2;i<=n;i++){
		int fa=read();
		add(fa,i);add(i,fa);
	}
	while(m--)w[read()]++;
	for(int k=1;k<=n;k++){
		LL sum=w[k];
		for(int i=p[k];i;i=e[i].nt){
			int kk=e[i].to;
			sum+=w[kk];
		}
		ans+=(1+sum)*sum>>1;
	}
	printf("%lld",ans)	;
} 

