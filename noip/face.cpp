#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN=20000;
int n, m, a, b, c;
int T, now;
double f[MAXN], sum[2][MAXN];
int main(){
//	freopen("face.in", "r", stdin);
//	freopen("face.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        memset(f, 0, sizeof(f));
        memset(sum, 0, sizeof(sum));
        scanf("%d %d", &m, &c);
        scanf("%d %d %d", &n, &a, &b);
        if(m+c>n*b) printf("mdzz\n");
        now=1;
        for(int i=0; i<=b*n; ++i) sum[0][i]=1;
        for(int i=1; i<=n; ++i, now^=1){
            for(int j=0; j<a*i; ++j) sum[now][j]=0;
            for(int j=a*i; j<=b*n; ++j){
                double t= j>b? sum[now^1][j-b-1]: 0;
                f[j]=(sum[now^1][j-a]-t)/(b-a+1);
                sum[now][j]= j==0? f[j]: sum[now][j-1]+f[j];
            }
        }
        printf("%.5f\n", m==0? sum[now^1][m+c]: sum[now^1][m+c]-sum[now^1][m-1]);
    }
    return 0;
}
