#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[105][105];
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int n;
	cin>>n;
	char s;
	memset(a, -1, sizeof(a));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>s;
			if(s == '#')
			a[i][j] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 1 && a[i][j + 1] == 1 && a[i][j - 1] == 1 && a[i - 1][j] == 1 && a[i + 1][j] == 1){
				a[i][j] = -1;a[i][j + 1] = -1;a[i][j - 1] = -1;a[i - 1][j] = -1;a[i + 1][j] = -1;
			}
		}
	}
	bool flag = false;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] > 0){
				flag = true;
				break;
			}
		}
	}
	if(flag) cout<<"NO";
	else cout<<"YES";
	return 0;
}
