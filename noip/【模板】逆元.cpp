#include<bits/stdc++.h>
#define maxn 3E6
using namespace std;
typedef long long ll;
ll inv[maxn];
int main(){
	int n , m;
	scanf("%d%d", &n, &m);
	inv[1] = 1;
	printf("%lld\n", inv[1]);
	for (int i = 2; i <= n; i++){
		inv[i] = (ll)(m - m / i) * inv[m % i] % m;
		printf("%lld\n", inv[i]);
	}
	return 0;
} 
