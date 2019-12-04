#include<cmath>
#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b){x=1,y=0;return;}
    exgcd(b,a%b,x,y);
    ll t=x;
    x=y,y=t-a/b*y;
}//扩欧模板
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll a,b,c,x,y,t;
        ll k;
        scanf("%lld%lld%lld",&a,&b,&k);
        if (a > b) swap(a, b);
        if (b % a == 0) {
            if (b / a - 1 < k)
                puts("OBEY");
            else puts("REBEL");
            continue;
        }
        c = 1;
        ll d=gcd(a,b);
        
        a/=d,b/=d,c/=d;//同除公约数，不然遍历通解会有遗漏
        exgcd(a,-b,x,y);//得到ax+by=1的一组解
        x*=c,y*=c;//得到ax+by=c的一组解
        if(x<=0)
        {
            t=abs(x)/b+1;
            x=x%b+b;//负数取模较特殊
            y-=t*a;
            if(y<=0)//当x变化为最小正整数解时，y最大，若y依然小于0，则没有正整数解
            {
                y = y % a + a;
                
            }
            ll L = 1, R = (ll)1e18 / b;
            ll v = (y + 1) * b;
            ll ans2 = 0;
            while (L <= R) {
                ll mid = (L + R) >> 1;
                if (mid * a < v) {
                    ans2 = max(ans2, mid);
                    L = mid + 1;
                }
                else R = mid - 1;
            }
            if (ans2 - x + 1ll >= k) puts("REBEL");
            else puts("OBEY");
            continue;
        }
        if(y<=0)//这几行与上几行同理
        {
            t=abs(y)/a+1;
            y=y%a+a;
            x-=t*b;
            if(x<=0)
            {
                x = x % b + b;
                
            }
            ll L = 1, R = (ll)1e18 / b;
            ll v = (y + 1) * b;
            ll ans2 = 0;
            while (L <= R) {
                ll mid = (L + R) >> 1;
                if (mid * a < v) {
                    ans2 = max(ans2, mid);
                    L = mid + 1;
                }
                else R = mid - 1;
            }
            if (ans2 - x + 1ll >= k) puts("REBEL");
            else puts("OBEY");
            continue;
        }//此时，x>0,y>0
        t=x/b;
        x-=t*b;//等价写法： x%=b
        if(!x)x+=b,t--;//细节，特判
        y+=t*a;//此时，x最小，对应的，y最大
        ll xmin=x,ymax=y;
        t=y/a;
        y-=t*a;
        if(!y)y+=a,t--;
        x+=t*b;
        ll L = 1, R = (ll)1e18 / b;
        ll v = (y + 1) * b;
        ll ans2 = 0;
        while (L <= R) {
            ll mid = (L + R) >> 1;
            if (mid * a < v) {
                ans2 = max(ans2, mid);
                L = mid + 1;
            }
            else R = mid - 1;
        }
        if (ans2 - xmin + 1ll >= k) puts("REBEL");
        else puts("OBEY");
        continue;
    }
    return 0;
}