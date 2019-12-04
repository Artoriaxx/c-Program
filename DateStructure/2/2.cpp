#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
struct stack {
    char a[N];
    int cnt = 0;
    void push(char x) {
        a[++cnt] = x;
    }
    void pop() {
        cnt--;
    }
    bool empty() {
        return cnt == 0;
    }
    char top() {
        return a[cnt];
    }
    void clear() {
        cnt = 0;
    }
} sta;
char in[N];
bool check(char ch) {
    if (ch == '(' || ch == '[') return 1;
    else return 0;
}
bool match(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']')) return 1;
    else return 0;
}
int main() {
    freopen("2.txt", "r", stdin);
    scanf("%s", in);
    int len = strlen(in);
    sta.clear();
    bool flag = true;
    for (int i = 0; i < len; i++) {
        if (check(in[i])) sta.push(in[i]);
        else {
            char ch = sta.top();
            sta.pop();
            if (match(ch, in[i])) continue;
            else {
                flag = false;
                break;
            }
        }
    }
    if (!sta.empty()) flag = false;
    if (flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}