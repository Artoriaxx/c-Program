#include<bits/stdc++.h>
#define p 163
using namespace std;
char s[1600];
vector<int> v;
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%s", s + 1);
		unsigned long long h = 0;
		for (int j = 1; j <= strlen(s + 1); j++){
			h = h * p + s[j];
		}
		v.push_back(h);
	}
	sort(v.begin(), v.end());
	int ans = unique(v.begin(), v.end()) - v.begin();
	printf("%d", ans);
	return 0;
} 
