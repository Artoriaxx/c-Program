#include<iostream>
#include<cstdio>
using namespace std;
char s[27] = {'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main(){
//	freopen("str.in","r",stdin);
//	freopen("str.out","w",stdout);
	int n, k;
	cin>>n>>k;
	if(k == 1 && n == 1){
		cout<<"a";
		return 0;
	}
	if(k == 1 && n > 1){
		cout<<"-1";
		return 0;
	} 
	else if(k > n){
		cout<<"-1";
		return 0;
	}
	if(k == n){
		for(int i = 1; i <= n; i++){
			cout<<s[i];
		}
		return 0;
	}
	bool flag = false;
	for(int i = 1; i <= n - k + 2; i++){
		if(!flag){
			cout<<"a";
			flag = true;
		}
		else{
			cout<<"b";
			flag = false;
		}
	}
	for(int i = 3; i <= k; i++){
		cout<<s[i];
	}
	return 0;
}
