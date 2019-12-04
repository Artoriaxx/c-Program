#include<iostream>
#define maxn 100010
#define seed 233
#define ll long long
using namespace std;
ll pow[maxn],len[2],h[2][maxn];char s[2][maxn];
inline void init(){
	pow[0] = 1;
	for(int i = 1; i <= len[0]; i++) pow[i] = pow[i - 1] * seed;
	for(int t = 0; t <= 1; t++){
		h[t][len[t] + 1] = 0;
		for(int i = len[t]; i >= 1; i--){
			h[t][i] = h[t][i + 1] * seed + s[t][i];
		}
	}
}
inline int hash(int t,int l,int len){
	return h[t][l] - h[t][l + len] * pow[len];
}
inline int lcp(int x,int y){
	if (s[0][x] != s[1][y]) return 0;
	int l = 1, r = min(len[0] - x + 1, len[1] - y + 1), ans = 1;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (hash(0, x, mid) == hash(1, y, mid)){
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}
int f[maxn][35];
int main(){
	int k;
	cin>>len[0]>>s[0] + 1>>len[1]>>s[1] + 1>>k;
	init();
	for(int i = 0; i <= len[0] - 1; i++){
		for(int j = 0; j <= k; j++){
			f[i + 1][j] = max(f[i + 1][j], f[i][j]);
			int len1 = lcp(i + 1, f[i][j] + 1);
			f[i + len1][j + 1] = max(f[i + len1][j + 1], f[i][j] + len1);
		}
	}
	for(int i = 1; i <= k; i++){
		if(f[len[0]][i] == len[1]){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
