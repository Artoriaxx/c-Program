#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
	int n, k;
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a + 1, a + 1 + n);
	int m = unique(a + 1, a + n + 1) - a - 1;
	cout<<min(n - k, m);
	return 0;
} 
