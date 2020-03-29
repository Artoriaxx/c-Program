#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> q;
    q.push(1);
    q.push(10);
    q.push(5);
    printf("%d\n", q.top());
    return 0;
}