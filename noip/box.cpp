#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a[5050],f[5050];
int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a + 1, a + n + 1);
	int t = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= t; j++){
			if(a[i] >= f[j]){
				f[j]++;
				break;
			}
			else if(j == t){
				t++;
				f[t]++;
				break;
			}
		}
	}
	cout<<t;
	return 0;
}
