#include<cstdio>
#include<iostream>
using namespace std;
struct node{
	int x, y, k;
}a[25];
int main(){
	int d, n, x, y, k;
	scanf("%d%d", &d, &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].k);
	}
	int l,r,u,b;
	int cnt = 0; int cnt1 = 0;
	int ans = 0; int ans1 = 0; int ans2 = 0;
	for(int i = 0; i <= 128; i++){
		for(int j = 0; j <= 128; j++){
		    cnt1 = 0;
			if(i - d < 0) l = 0; else l = i - d;
			if(i + d > 128) r = 128; else r = i + d;
			if(j - d < 0) u = 0; else u = j - d;
			if(j + d > 128) b = 128; else b = j + d;
			for(int i = 1; i <= n; i++){
				if(a[i].x <= r && a[i].x >= l && a[i].y >= u && a[i].y <= b){
					cnt1 += a[i].k;
				}
			}
			if(cnt1 > ans1){
				ans1 = cnt1;
				cnt = 1;
			}
			else if(cnt1 == ans1){
				cnt++;
			}
		}
	}
	printf("%d %d", cnt, ans1);
	return 0;
} 
