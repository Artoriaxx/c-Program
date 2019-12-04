#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
struct date {
    int yy, mm, dd;
    date() {}
    date(int yy, int mm, int dd): yy(yy), mm(mm), dd(dd) {}
};
struct stack {
    date a[N];
    int cnt = 0;
    void push(date x) {
        a[++cnt] = x;
    }
    void pop() {
        cnt--;
    }
    bool empty() {
        return cnt == 0;
    }
    date top() {
        return a[cnt];
    }
    void clear() {
        cnt = 0;
    }
} sta1, sta2;
bool cmp(date a, date b) {//a小返回1
    if (a.yy == b.yy && a.mm == b.mm) {
        return a.dd < b.dd;
    }
    else if (a.yy == b.yy) {
        return a.mm < b.mm;
    }
    else return a.yy < b.yy;
}
int main() {
    freopen("3.txt", "r", stdin);
    char ch[2];
    bool flag = true;
    while (scanf("%s", ch) && flag) {
        switch(ch[0]) {
            case 'I': {
                int yy, mm, dd;
                scanf("%d/%d/%d", &yy, &mm, &dd);
                date now = date(yy, mm, dd);
                while (1) {
                    if (sta1.empty()) {
                        sta1.push(now);
                        break;
                    }
                    date x = sta1.top();
                    if (cmp(now, x)) {
                        sta1.push(now);
                        break;
                    }
                    else {
                        sta1.pop();
                        sta2.push(x);
                    }
                }
                while (!sta2.empty()) {
                    sta1.push(sta2.top());
                    sta2.pop();
                }
                break;
            }
            case 'O': {
                if (sta1.empty()) printf("ERROR\n");
                else {
                    date now = sta1.top();
                    printf("%d/%d/%d\n", now.yy, now.mm, now.dd);
                    sta1.pop();
                }
                break;
            }
            case 'B': {
                flag = false;
                break;
            }
        }
    }
    return 0;
}