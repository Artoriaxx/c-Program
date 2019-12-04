#include<iostream>
#define maxn 300000
using namespace std;
int a[maxn];
int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] > 0){
			if(a[i] >= 2) a[i] -= 2;
			else if(a[i + 1] > 0){
				a[i] -= 1;
				a[i + 1] -= 1;
			}
		}
	}
	int flag = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] != 0) flag = 1;
	}
	if(!flag) cout<<"YES";
	else cout<<"NO";
	return 0;
}
