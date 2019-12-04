#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1e6 + 10;
int f[maxn];
inline int getnum(){
	char c; bool flag = false; int ans = 0;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1); 
}
int main(){
	int n, m;
	n = getnum(); m = getnum();
	for(int i = 1; i <= m; i++){
		int a, b, c; 
		a = getnum();b = getnum();c = getnum();
		f[a] += c; f[b] -= c;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if (f[i] > 0) ans += f[i];
	}
	cout<<ans<<endl;
}
