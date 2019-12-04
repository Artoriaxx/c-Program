#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define re register int
#define p 998244353
#define ll long long
using namespace std;
inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
inline ll fpow(ll a, int b){
	ll base = a % p, ans = 1;
	while (b){
		if (b & 1){
			(ans *= base) %= p;
		}
		(base *= base) %= p;
		b >>= 1;
	}
	return ans;
}
int main(){
	int t;
	t = getnum();
	while (t--){
		int n = getnum();
		ll a = 0, b = 0;
		for (re i = 1; i <= n; i++){
			int x = getnum();
			a = (a + (ll)i * x) % p,b = (b + (ll)i * i % p * x) % p;
		}
		for (re i = 1; i <= n; i++){
			int x = getnum();
			a = (a - (ll)i * x) % p,b = (b - (ll)i * i % p * x) % p;
		}
		if (!a) cout << "0" << endl;
		else cout << "1" << " " << ((ll)b * fpow(a, p - 2) % p + p) % p << endl;
	}
}
