#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
#define inf 100050
using namespace std;
int cnt[inf];int a[inf];
int main(){
	freopen("del.in","r",stdin);
	freopen("del.out","w",stdout);
	int n, k;
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a + 1, a + n + 1);
	int vis = 1,t = a[1];
	int i = 1;
	while(i <= n){
		while(t == a[i]){
			cnt[vis]++;
			i++;
		}
		t = a[i];
		vis++;
	}
	vis--;
	int ans;
	for(int i = 1; i <= vis; i++){
		cnt[i]--;
		if(cnt[i] > 0 && k >= cnt[i]){
			k -= cnt[i];
			continue;
		}
		if(cnt[i] > 0 && k <= cnt[i]){
			k = 0;
			break;
		}
	}
	ans = vis - k;
	cout<<ans;
	return 0;
}
