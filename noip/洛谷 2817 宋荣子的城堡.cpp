#include<iostream>
#define ll long long
#define p 1000000007
using namespace std;
ll fastpow(ll a,ll b){
	ll ans = 1,base = a;
	while(b){
		if(b & 1){
			(ans *= base) %= p;
		}
		(base *= base) %= p;
		b >>= 1;
	}
	return ans;
}
int main(){
//	freopen("castle.in","r",stdin);
//	freopen("castle.out","w",stdout);
	int n, k;
	cin>>n>>k;
	ll ans1 = fastpow(n - k, n - k) % p;
	ll ans2 = fastpow(k, k - 1) % p;
	ll ans = (ans1 * ans2) % p;
	cout<<ans;
	return 0;
}
