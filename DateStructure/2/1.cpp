#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
struct stack {
    int a[N];
    int cnt = 0;
    void push(int x) {
        a[++cnt] = x;
    }
    void pop() {
        cnt--;
    }
    bool empty() {
        return cnt == 0;
    }
    int top() {
        return a[cnt];
    }
    void clear() {
        cnt = 0;
    }
} sta;

int main() {
    freopen("1.txt", "r", stdin);
    int n, d;
    scanf("%d%d", &n, &d);
    sta.clear();
    while (n) {
        sta.push(n % d);
        n /= d;
    }
    printf("The converted number is\n");
    while (!sta.empty()) {
        printf("%d", sta.top());
        sta.pop();
    }
    return 0;
}