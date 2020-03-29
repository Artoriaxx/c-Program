#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 50;
int pre[N];
int a[N];
int b[N];
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    // ll ans1 = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i + 1; j <= n; j++) {
    //         ans1 ^= (a[i] + a[j]);
    //     }
    // }
    // printf("%lld\n", ans1);
    ll ans = 0;
    for (int i = 0; i < 25; i++) {//逐位考虑每一位上结果是否为1
        int mod = 1 << (i + 1);
        for (int j = 1; j <= n; j++) {//看这一位的影响
            b[j] = a[j] % mod;
        }
        sort(b + 1, b + n + 1);
        ll s = 0;
        for (int j = 1; j <= n; j++) {//枚举两数相加的其中一个数,看两数之和这一位为1的数量
            //取模之后两数相加的范围[ 0, 2^(k+2) )
            int l = lower_bound(b + 1, b + n + 1, (1 << i) - b[j]) - b;//第k位为1的范围1:[ 2^k, 2^(k+1) )
            int r = lower_bound(b + 1, b + n + 1, (1 << (i + 1)) - b[j]) - b - 1;//注意左闭右开
            s += r - l + 1;
            l = lower_bound(b + 1, b + n + 1, (1 << (i + 1)) + (1 << i) - b[j]) - b;//范围2:[ 2^(k+1)+2^k, 2^(k+2) )
            r = lower_bound(b + 1, b + n + 1, (1 << (i + 2)) - b[j]) - b - 1;
            s += r - l + 1;
            if ((b[j] + b[j]) & (1 << i)) s--;//如果自己+自己也符合要求,数量--;
        }
        s /= 2;//无序数对变有序
        if (s & 1) ans += (1 << i);
    }
    printf("%lld\n", ans);
    return 0;
}