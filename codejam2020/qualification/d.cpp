/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-04 20:06:42
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-04 22:12:14
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 150;
int a[N];
int main() {
    int b;
    int t; cin >> t >> b;
    fflush(stdin);
    while (t--) {
        
        int x;
        cout << 1 << endl;
        fflush(stdout);
        cin >> x;
        fflush(stdin);
        a[1] = x;
        cout << b << endl;
        fflush(stdout);
        cin >> x;
        fflush(stdin);
        a[b] = x;
        int l = 2, r = b - 1;
        int cnt = 2;
        while (l <= r) {
            cout << l << endl;
            fflush(stdout);
            cin >> x;
            fflush(stdin);
            a[l] = x;
            cout << r << endl;
            fflush(stdout);
            cin >> x;
            fflush(stdin);
            a[r] = x;
            cnt += 2;
            if (cnt % 10 == 0) {
                int q1 = 0, q2 = 0;
                for (int i = 1; i <= l; i++) {
                    if (a[i] == 1 && a[b - i + 1] == 0) q1 = i;
                    if (a[i] == 0 && a[b - i + 1] == 1) q1 = i;
                    if (a[i] == 1 && a[b - i + 1] == 1) q2 = i;
                    if (a[i] == 0 && a[b - i + 1] == 0) q2 = i;
                }
                if (q1 == 0) {
                    cout << q2 << endl;
                    fflush(stdout);
                    cin >> x;
                    fflush(stdin);
                    cout << q2 << endl;
                    fflush(stdout);
                    cin >> x;
                    fflush(stdin);
                    if (x != a[q2]) {
                        for (int i = 1; i <= l; i++) {
                            a[i] ^= 1;
                            a[b - i + 1] ^= 1;
                        }
                    }
                }
                else if (q2 == 0) {
                    cout << q1 << endl;
                    fflush(stdout);
                    cin >> x;
                    fflush(stdin);
                    cout << q1 << endl;
                    fflush(stdout);
                    cin >> x;
                    fflush(stdin);
                    if (x != a[q1]) {
                        for (int i = 1; i <= l; i++) swap(a[i], a[b - i + 1]);
                        
                    }
                }
                else {
                    cout << q1 << endl;
                    fflush(stdout);
                    int ans1, ans2;
                    cin >> ans1; 
                    fflush(stdin);
                    cout << q2 << endl;
                    fflush(stdout);
                    cin >> ans2;
                    fflush(stdin);
                    if (ans1 != a[q1] && ans2 != a[q2]) {
                        for (int i = 1; i <= l; i++) {
                            a[i] ^= 1;
                            a[b - i + 1] ^= 1;
                        }
                    }
                    else if (ans1 == a[q1] && ans2 != a[q2]) {
                        for (int i = 1; i <= l; i++) {
                            a[i] ^= 1;
                            a[b - i + 1] ^= 1;
                            swap(a[i], a[b - i + 1]);
                        }
                    }
                    else if (ans1 != a[q1] && ans2 == a[q2]) {
                        for (int i = 1; i <= l; i++) swap(a[i], a[b - i + 1]);
                    }
                }
                cnt += 2;
            }
            l++; r--;
        }
        for (int i = 1; i <= b; i++) cout << a[i];
        cout << endl;
        fflush(stdin);
        char ch[2];
        scanf("%s", ch);
        fflush(stdin);
    }
    return 0;
}
