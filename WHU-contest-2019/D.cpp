#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
typedef long long ll;
ll fpow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = (ans * a) % mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans % mod;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		ll n,m;
		scanf("%lld%lld",&n,&m);
		if(n==1)printf("%lld\n",m-1);
		else{
			m--;
			long long tmp=1;
			long long ans=0;
			for(long long i=1;i<=n;i++){
				ans=(ans-tmp + mod)%mod;
				tmp=(((tmp*(m+i))%mod)*fpow(i, mod-2)) % mod;
			}
			ans=((ans+tmp)%mod+mod)%mod;
			printf("%lld\n",ans);
		}
	}
}