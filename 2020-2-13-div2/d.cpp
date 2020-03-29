#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    char dir;
    node() {}
    node(int val, char dir): val(val), dir(dir) {}
};
vector<node> ans;
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (k > 4 * n * m - 2 * n - 2 * m) {
        puts("NO");
        return 0;
    }
    puts("YES");
    if (n == 1) {
        if (k > m - 1) {
            k -= m - 1;
            ans.push_back(node(m - 1, 'R'));
        }
        else if (k > 0) {
            k = 0;
            ans.push_back(node(k, 'R'));
        }
        if (k > 0) ans.push_back(node(k, 'L'));
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %c\n", ans[i].val, ans[i].dir);
        }
        return 0;
    }
    if (m == 1) {
        if (k > n - 1) {
            k -= n - 1;
            ans.push_back(node(n - 1, 'D'));
        }
        else if (k > 0) {
            k = 0;
            ans.push_back(node(k, 'D'));
        }
        if (k > 0) ans.push_back(node(k, 'U'));
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %c\n", ans[i].val, ans[i].dir);
        }
        return 0;
    }
    if (k > n - 1) {
        k -= (n - 1);
        ans.push_back(node(n - 1, 'D'));
        k--;
        ans.push_back(node(1, 'R'));
    }
    else {
        
        ans.push_back(node(k, 'D'));
        k = 0;
    }
    if (k > 0) {
        for (int i = 2; i < m; i++) {
            if (k <= 0) {
                break;
            }
            if (k > n - 1) {
                k -= n - 1;
                ans.push_back(node(n - 1, 'U'));
            }
            else {
                
                ans.push_back(node(k, 'U'));
                k = 0;
                break;
            }
            if (k > n - 1) {
                k -= n - 1;
                ans.push_back(node(n - 1, 'D'));
                k--;
                ans.push_back(node(1, 'R'));
            }
            else {
                
                ans.push_back(node(k, 'D'));
                k = 0;
                break;
            }
        }
    }
    if (k > 0) {
        if (k > n - 1) {
            k -= n - 1;
            ans.push_back(node(n - 1, 'U'));
        }
        else if (k > 0) {
            
            ans.push_back(node(k, 'U'));
            k = 0;
        }
        if (k > n - 1) {
            k -= n - 1;
            ans.push_back(node(n - 1, 'D'));
        }
        else if (k > 0) {
            
            ans.push_back(node(k, 'D'));
            k = 0;
        }
        if (k > m - 1) {
            k -= m - 1;
            ans.push_back(node(m - 1, 'L'));
            k--;
            ans.push_back(node(1, 'U'));
        }
        else if (k > 0) {
            
            ans.push_back(node(k, 'L'));
            k = 0;
        }
    }
    if (k > 0) {
        for (int i = 2; i < n; i++) {
            if (k <= 0) {
                break;
            }
            if (k > m - 1) {
                k -= m - 1;
                ans.push_back(node(m - 1, 'R'));
            }
            else {
                
                ans.push_back(node(k, 'R'));
                k = 0;
                break;
            }
            if (k > m - 1) {
                k -= m - 1;
                ans.push_back(node(m - 1, 'L'));
                k--;
                ans.push_back(node(1, 'U'));
            }
            else {
                
                ans.push_back(node(k, 'L'));
                k = 0;
                break;
            }
        }
    }
    if (k > 0) {
        if (k > m - 1) {
            k -= m - 1;
            ans.push_back(node(m - 1, 'R'));
        }
        else if (k > 0) {
            
            ans.push_back(node(k, 'R'));k = 0;
        }
        if (k > m - 1) {
            k -= m - 1;
            ans.push_back(node(m - 1, 'L'));
        }
        else if (k > 0) {
            
            ans.push_back(node(k, 'L'));k = 0;
        }
    }
    int t = ans.size();
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].val == 0) t--; 
    }
    
    printf("%d\n", t);
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].val != 0) printf("%d %c\n", ans[i].val, ans[i].dir);
    }
    return 0;
}