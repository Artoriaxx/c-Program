#include<cstdio>
#include<iostream>
#define maxn 1000050
using namespace std;
long long getnum(){
	long long ans = 0; char c; bool flag = false;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
long long a[maxn];
int main(){
	int n = getnum(); long long m = getnum();
	for(int i = 1; i <= n; i++){
		a[i] = getnum();
	}
	long long l = 0; long long r = 1000000050;
	long long ans = 0,ans1 = 0;
	long long mid;
	while(l <= r){
		mid = (l + r) / 2;
		ans = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] <= mid) continue;
			else{
				ans += a[i] - mid;
			}
		}
		if(ans >= m){
			l = mid + 1;
			ans1 = max(mid, ans1);
		}
		else r = mid - 1;
	}
	printf("%lld", ans1);
	return 0;
}
