//想求x在n！中的因数，只需要不停地ans+=n/x，n/=x递归求解即可 
#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll n, m;
ll cal(ll x, ll y){
    ll umi = 0ll;
    ll base = x;
    while (base <= n) umi += n / base, base *= x;//把除法转换为乘法，要不会爆ll 
    return umi / y;
}
int main(){
    while(scanf("%lld%lld", &n, &m) >= 2){
        ll t, s;
        ll ans = 0x7fffffffffffffff;
        for(ll i = 2; i <= sqrt(m); i++){
            if(m % i == 0){
                t = i, s = 0;
                while(m % i == 0){
                    s++, m /= i;
                }
                ans = min(ans, cal(t, s));
            }
        }
        if(m > 1) ans = min(ans, cal(m, 1));
        cout << ans <<endl;
    }
    return 0;
} 
