#include <bits/stdc++.h>
using namespace std;
int sz = 5;
int read() {
    char c; int ans = 0; int flag = 1;
    while (!isdigit(c = getchar()));
    if (c == '-') flag = -1; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * flag;
}
void findmid(int a[], int l, int r) {
    int group;
    do {
        group = ceil(1.0 * (r - l + 1) / sz);
        for (int i = 1; i <= group; i++) {
            int nowl = l + (i - 1) * sz, nowr = min(r, l + i * sz - 1);
            sort(a + nowl, a + nowr + 1);
            swap(a[l + i - 1], a[(nowl + nowr) >> 1]);
        }
        r = l + group - 1;
    } while (group > 1);
}
int findkth(int a[], int l, int r, int k) {
    if (r - l + 1 <= 25) {
        sort(a + l, a + r + 1);
        return a[k];
    }
    findmid(a, l, r);
    int lt = l, gt = r, i = l + 1, pivot = a[l];
    while (i <= gt) {
        if (a[i] < pivot) swap(a[lt++], a[i++]);
        else if (a[i] > pivot) swap(a[i], a[gt--]);
        else i++; 
    }
    if (k >= lt && k <= gt) return a[lt];
    else if (k > gt) return findkth(a, gt + 1, r, k);
    else return findkth(a, l, lt - 1, k);
}
int *a;
int main() {
    int n, k;
    n = read(); k = read();
    a = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) a[i] = read();
    printf("%d\n", findkth(a, 1, n, k));
    return 0;
}