#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 100010
#define maxm 1200010

using namespace std;

int a[maxn][4];
int f[maxn][5], ans, N, n;
int t[maxm];

struct BIT
{
    int a[maxm], N;
    
    int lowbit(int x){
        return x & -x;
    }
    
    int query(int x){
        int ans = -1;
        while(x){
        	ans = max(ans, a[x]);
        	x -= lowbit(x);
        }
        return ans;
    }
    
    void update(int x, int v){
        while(x <= N){
        	a[x] = max(a[x], v);
        	x += lowbit(x);
        }
    }
    
    void init(int n){
        for(N = 1; N < n; N <<= 1);
        memset(a, 0, sizeof(a));
    }
    
} b[5][2];

int res[5];

inline int id(int j)
{
    return j == 4 ? 3 : j;
}

int main()
{
    scanf("%d", &n);
    for (int j = 1; j <= 3; j++)
    	for (int i = 1; i <= n ; i++)
        	scanf("%d", &a[i][j]), t[++N] = a[i][j];
    
    sort(t + 1, t + N + 1);
    N = unique(t + 1, t + N + 1) - t - 1;
    for (int j = 1; j <= 3; j++)
    	for (int i = 1; i <= n ; i++)
        	a[i][j] = lower_bound(t + 1, t + N + 1, a[i][j]) - t;
    
    for (int j = 1; j <= 4; j++)
        b[j][0].init(N), b[j][1].init(N);
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            res[j] = 0;
            for (int k = 1; k <= 4; k++)
            if(!(j == 3 && k == 4 || j == 4 && k == 3))
                res[j] = max(res[j], b[k][j & 1].query((j & 1) ? a[i][id(j)] : N - a[i][id(j)] + 1));//�ж����������½����ֱ�ת�� 
            ans = max(ans, ++res[j]);//С��n - a[i][id(j)] + 1��Ϊ����a[i][id(j)] 
        }
        
        for (int j = 1; j <= 4; j++)
            b[j][1].update(a[i][id(j)], res[j]),//��¼������ת��
            b[j][0].update(N - a[i][id(j)] + 1, res[j]);//��¼�½���ת�� 
    }
    
    printf("%d\n", ans);

    return 0;
}
