#include<iostream>
#include<cstring>
using namespace std;
int cnt[20],a[5],ans;
inline int calc(){
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= 14; i++)
		a[cnt[i]]++;
	int cal = 0;
	while (a[4] && a[2] >= 2) a[4]--, a[2] -= 2, cal++;
	while (a[4] && a[1] >= 2) a[4]--, a[1] -= 2, cal++;
	while (a[4] && a[2]) a[4]--, a[2]--, cal++;
	while (a[3] && a[2]) a[3]--, a[2]--, cal++;
	while (a[3] && a[1]) a[3]--, a[1]--, cal++;
	return cal + a[4] + a[3] + a[2] + a[1];
}
void dfs(int now){
	if (now >= ans) return;
	int tmp = calc();
	ans = min(ans, now + tmp);
	for (int i = 1; i <= 11; i++){
		if (cnt[i] >= 3 && cnt[i + 1] >= 3){
		    cnt[i] -= 3;cnt[i + 1] -= 3;
			dfs(now + 1);
			int j;
			for (j = i + 2; j <= 12; j++){
				if (cnt[j] < 3) break;
				else{
					cnt[j] -= 3;
					dfs(now + 1);
				}
			}
			for (int k = i; k < j; k++){
				cnt[k] += 3;
			}
	    }
	}
	
	for (int i = 1; i <= 10; i++){
		if (cnt[i] >= 2 && cnt[i + 1] >= 2 && cnt[i + 2] >= 2){
			cnt[i] -= 2;cnt[i + 1] -= 2;cnt[i + 2] -= 2;
			dfs(now + 1);
			int j;
			for (j = i + 3; j <= 12; j++){
				if(cnt[j] < 2) break;
				else{
					cnt[j] -= 2;
					dfs(now + 1);
				}
			}
			for (int k = i; k < j; k++){
				cnt[k] += 2;
			}
	    }
	}
	
	for (int i = 1; i <= 8; i++){
		if (cnt[i] && cnt[i + 1] && cnt[i + 2] && cnt[i + 3] && cnt[i + 4]){
			cnt[i]--; cnt[i + 1]--; cnt[i + 2]--; cnt[i + 3]--; cnt[i + 4]--;
			dfs(now + 1);
			int j;
			for (j = i + 5; j <= 12 ;j++){
				if(!cnt[j]) break;
				else{
					cnt[j]--;
					dfs(now + 1);
				}
			}
			for(int k = i; k < j; k++){
				cnt[k]++;
			}
	    }
	}
}
inline void init(){
	memset(cnt, 0, sizeof(cnt));
}
int main(){
	int t,n;
	cin>>t>>n;
	int x,b;
	while (t--){
		init();
		for (int i = 1; i <= n; i++){
			cin>>x>>b;
			if(x == 1 || x == 2) cnt[x + 11]++;
			else if(x != 0) cnt[x - 2]++;
			else cnt[x+14]++;
		}
		ans = 0x3f3f3f3f;
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
