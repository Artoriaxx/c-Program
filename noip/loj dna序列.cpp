#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define seed 233
#define ll unsigned long long
#define maxn 5000050
using namespace std;
char s[maxn];
int len;
ll pow[maxn];
ll h[maxn];
inline void init(){
	pow[0] = 1;
	for (int i = 1; i <= len; i++){
		pow[i] = pow[i - 1] * seed;
	}
	h[len + 1] = 0;
	for (int i = len; i >= 1; i--){
		h[i] = h[i + 1] * seed + s[i] - 'A';
	}
}
inline ll hash(int l, int len1){
	return h[l] - h[l + len1] * pow[len1];
}
vector<ll> v;
int main(){
	scanf("%s", s + 1);
	len = strlen(s + 1);
	int len2;
	scanf("%d", &len2);
	init();
	for (int i = 1; i <= len - len2 + 1; i++){
		ll x = hash(i, len2);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	ll ans = 0, cnt = 0;
	for (int i = 0; i < v.size(); i++){
		if (i == 0){
			cnt++;
		}
		else {
			if (v[i] == v[i - 1]){
				cnt++;
			}
			else cnt = 1;
		}
		ans = max(ans, cnt);
	}
	printf("%lld", ans);
	return 0;
}
