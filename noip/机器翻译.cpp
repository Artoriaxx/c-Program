#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
inline int getnum(){
    int ans = 0; bool flag = false; char c;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') flag = true; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * (flag ? -1 : 1);
}
int m, n;
int vis[maxn]; 
vector<int> tmp;
int main(){
	m = getnum(), n = getnum();
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int a = getnum();
		if (!vis[a]){
			ans++;
			if (tmp.size() < m){
				vis[a] = 1;
				tmp.push_back(a);
			}
			else {
				int x = tmp[0];
				vis[x] = 0;
				tmp.erase(tmp.begin()); 
				tmp.push_back(a);
				vis[a] = 1;
			}
		}
		else continue;
	}
	printf("%d", ans);
	return 0;
}
