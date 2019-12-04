#include<bits/stdc++.h>
#define maxn 10000050 
using namespace std;
int isprime[maxn], prime[maxn >> 1];
int n, m, cnt;
inline void init(){
	isprime[1] = 1;// ÎğÍü 
	for (int i = 2; i <= n; i++){
		if (!isprime[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++){
			isprime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int main(){
	n = getnum(), m = getnum();
	init();
	for (int i = 1; i <= m; i++){
		int x = getnum();
		if (isprime[x]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
	
