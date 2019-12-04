#include<iostream>
#include<algorithm>
#define maxn 100050
using namespace std;
struct node{
	int a;int b;
}a[maxn];
node cnt[maxn];
int cmp(node a,node b){
	if(a.a == b.a){
		return a.b < b.b;
	}
	else{
		return a.a < b.a;
	}
}
int n;
int solve(int a,int b){
	int j = a,ans = 0;
	for(int i = a; i <= b; i++){
		while(j < b && cnt[j + 1].b - cnt[i].b < n) j++;
		ans = max(ans, j - i + 1);
	}
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i].a>>a[i].b;
	}
	sort(a + 1, a + n + 1, cmp);
	int i = 1;
	int vis = 1,t = a[1].b;
	int p = a[1].a;
	while(i <= n){
		while(t == a[i].b && p == a[i].a){
			i++;
		}
		cnt[vis].a = a[i - 1].a;
		cnt[vis].b = a[i - 1].b;
		t = a[i].b;p = a[i].a;
		vis++;
	}
	int ans = 0;
	int j;
	for(i = 2,j = 1; i <= vis; i++){
		if(cnt[i].a != cnt[i - 1].a){
			ans = max(ans, solve(j, i - 1));
			j = i;
		}
	}
	ans = max(ans,solve(i,j - 1));
	cout<<n - ans;
	return 0;
}
