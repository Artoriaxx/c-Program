#include<bits/stdc++.h>
#define re register int
#define esp 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int n, m;
double x[25], y[25];
bool same(double x, double y){
	return fabs(x - y) < esp;
}
int g[25][25];
int f[(1 << 20) + 50];
inline int init(){
	memset(g, 0, sizeof(g));
	int k = 1 << n;
	for (re i = 1; i < k; i++){
		f[i] = inf;
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		init();
		for (re i = 1; i <= n; i++){
			scanf("%lf%lf", &x[i], &y[i]);
		}
		for (re i = 1; i <= n; i++){
			for (re j = i + 1; j <= n; j++){
				if (same(x[i], x[j])) continue;
				double a = (x[j] * y[i] - x[i] * y[j]) / 
				(x[i] * x[j] * (x[i] - x[j]));
				if (a >= 0) continue;
				double b = (y[j] - a * x[j] * x[j]) / x[j];
				for (re k = 1; k <= n; k++){
					if(same(a * x[k] * x[k] + b * x[k], y[k]))
					g[i][j] |= (1 << (k - 1));
				}
			}
		}
		f[0] = 0;//一只都不打 
		int ki = (1 << n);//状态总数
		for (re i = 0; i < ki; i++){
			for (re j = 1; j <= n; j++){
				if (!(i & (1 << (j - 1)))){//找到最小的那只没被打的猪
					for (re k = j; k <= n; k++){
						if (k == j){ //单独打掉这只猪 
							f[i | (1 << (j - 1))] = min(f[i | (1 << (j - 1))], f[i] + 1);
							continue;
						}
						if (same(x[j], x[k])) continue;
						f[i | g[j][k]] = min(f[i | g[j][k]], f[i] + 1);
					}
					break;
				}
			}
		}
		printf("%d\n", f[(1 << n) - 1]);
	}
	return 0;
}
