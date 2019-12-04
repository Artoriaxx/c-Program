#include<iostream>
using namespace std;
int ans1,ans2,a[250],b[250];
inline void check(int x){
	if(a[x] == 0){
		if(b[x] == 2 || b[x] == 3) ans1++;
		if(b[x] == 1 || b[x] == 4) ans2++;
	}
	else if(a[x] == 1){
		if(b[x] == 0 || b[x] == 3) ans1++;
		if(b[x] == 2 || b[x] == 4) ans2++;
	}
	else if(a[x] == 2){
		if(b[x] == 1 || b[x] == 4) ans1++;
		if(b[x] == 0 || b[x] == 3) ans2++;
	}
	else if(a[x] == 3){
		if(b[x] == 2 || b[x] == 4) ans1++;
		if(b[x] == 0 || b[x] == 1) ans2++;
	}
	else if(a[x] == 4){
		if(b[x] == 0 || b[x] == 1) ans1++;
		if(b[x] == 2 || b[x] == 3) ans2++;
	}
}
int main(){
	int n, n1, n2;
	cin>>n>>n1>>n2;
	for(int i = 1; i <= n1; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n2; i++){
		cin>>b[i];
	}
	for(int i = n1 + 1; i <= n; i++){
		a[i] = a[i - n1];
	}
	for(int i = n2 + 1; i <= n; i++){
		b[i] = b[i - n2];
	}
	for(int i = 1; i <= n; i++){
		check(i);
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
