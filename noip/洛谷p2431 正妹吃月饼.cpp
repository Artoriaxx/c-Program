#include<iostream>
using namespace std;
typedef long long ll;
ll a[65];
int main(){
	ll x, y;
	cin>>x>>y;
	ll base = x;
	int cnt = 0;
	while(base){
		a[++cnt] = base & 1;
		base >>= 1;
	}
	int ans = 0; 
	ll p = 1;
	for(int i = 1; i <= 63; i++){
		if(a[i] == 1) ans++;
		else{
			x += p << (i - 1);
			if(x <= y) ans ++;
		}
	}
	cout<<ans;
	return 0;
}
