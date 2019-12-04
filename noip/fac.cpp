#include<iostream>
using namespace std;
int n, m;
int cal(int x, int y){
	int umi = 0;
	for(int i = n; i; i /= x) umi += i / x;
	return umi / y;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int t, s;
		int ans = 2e9;
		for(int i = 2; i * i <= m; i++){
			if(m % i == 0){
				t = i, s = 0;
				while(m % i == 0){
					s++, m /= i;
				}
				ans = min(ans, cal(t, s));
			}
		}
		if(m > 1) ans = min(ans, cal(m, 1));
		cout << ans << endl;
	}
	return 0;
} 
