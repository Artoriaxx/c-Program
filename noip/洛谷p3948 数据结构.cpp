#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define maxn 105000
using namespace std;
inline ll getnum(){
    char c; ll ans = 0; bool flag = false;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') flag = true; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * (flag ? -1 : 1);
}
ll n1, opt1, mod1, min1, max1;
ll cnt[maxn], ans[maxn], tmp;
ll l, r, xi;
ll now;
char s1[5];
int main(){
    n1 = getnum(), opt1 = getnum();
    mod1 = getnum();
    min1 = getnum(), max1 = getnum();
    for (int i = 1; i <= opt1; i++){
        scanf("%s", s1);
        if (s1[0] == 'A'){
            l = getnum(), r = getnum(), xi = getnum();
            if (l > r) swap(l, r);
            cnt[l] += xi, cnt[r + 1] -= xi;
        }
        else if (s1[0] == 'Q'){
            l = getnum(), r = getnum();
            now = 0;
            int ans1 = 0;
            for (int j = 1; j <= r; j++){
                now += cnt[j];
                if(j >= l) ans1 += (((now * j) % mod1 >= min1) && ((now * j) % mod1 <= max1));
            }
            printf("%d\n", ans1);
        }
    }
    int final1 = getnum();
    memset(ans, 0, sizeof(ans));
    now = 0;
    for (int i = 1; i <= n1; i++){
        now += cnt[i];
        ans[i] = ans[i - 1] + (((now * i) % mod1 >= min1) && ((now * i) % mod1 <= max1));
    }
    for (int i = 1; i <= final1; i++){
        l = getnum(), r = getnum(); if (l > r) swap(l, r);
        printf("%d\n", ans[r] - ans[l - 1]);
    }
    return 0;
}
