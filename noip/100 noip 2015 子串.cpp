#include<cstdio>
#define p 1000000007
using namespace std;
char a[1050],b[250];
long long f[3][250][250],s[2][250][250];
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	f[0][0][0] = 1;
	for(int i = 1; i <= n; i++){
		f[i & 1][0][0] = 1;
		for(int j = 1; j <= m; j++){
			for(int kk = 1; kk <= k; kk++){
				if(a[i] == b[j])
					s[i & 1][j][kk] = (s[(i + 1) & 1][j - 1][kk] % p + f[(i + 1) & 1][j - 1][kk - 1] % p) % p;
				else
                    s[i & 1][j][kk] = 0;
                f[i & 1][j][kk] = (f[(i + 1) & 1][j][kk] % p + s[i & 1][j][kk] % p) % p;
			}
		}
	}
	printf("%lld", f[n & 1][m][k] % p);
	return 0;
}
