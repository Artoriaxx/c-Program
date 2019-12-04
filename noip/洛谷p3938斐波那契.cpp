#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[70];
inline ll getnum(){
	ll ans = 0; char c; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int main(){
	f[1] = f[2] = 1;
	for(int i = 3; i <= 65; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	int n;
	n = getnum();//找规律发现第i只兔子的父亲是它减去比它小的斐波那契数 
	for (int i = 1; i <= n; i++){
		ll a = getnum(), b = getnum();
		while (1){
			if (b > a) swap(a, b);
			if (a == b){
				printf("%lld\n", a);
				break;
			}
			int x = lower_bound(f + 1, f + 65 + 1, a) - f;
			a -= f[x - 1];
		}
	}
	return 0;
}
