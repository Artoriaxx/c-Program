#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, id;
    node() {}
    node(int x, int id): x(x), id(id) {}
};
vector<node> a;
int main() {
    freopen("3.txt", "r", stdin);
    int n;
    printf("Enter the number of people\n");
    scanf("%d", &n);
    printf("Enter the code of each people\n");
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(node(x, i));
    }
    int m;
    printf("Enter the initial password\n");
    scanf("%d", &m);
    int pos = 0;
    while (a.size() > 0) {
        pos = (pos  + m % a.size()) % a.size() ? (pos  + m % a.size()) % a.size() : a.size();
        pos--;
        printf("%d ", a[pos].id);
        m = a[pos].x;
        a.erase(a.begin() + pos);
    }
    return 0;
}