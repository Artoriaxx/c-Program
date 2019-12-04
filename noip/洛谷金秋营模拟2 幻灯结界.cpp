#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;
inline int read(){
	char c; int ans = 0; bool flag = false;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}

int n, x, y;

long long max1 = -5e9;
int main(){
	n = read(); x = read(); y = read();
	for (int i = 1; i <= n; i++){
		a[i] = read();
	}
	for (int i = 1; i <= n; i++){
		b[i] = read();
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= x; i++){
		a[i] = max(a[i] , y);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		if(max1 < b[i] - a[i]) max1 = max(0, b[i] - a[i]);
	}
	cout<<max1;
	return 0;
}
