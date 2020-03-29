#include <bits/stdc++.h>
using namespace std;
const int N = 3050;
char s[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += s[i] - '0';
        }
        if (sum % 2 == 0) {
            int pos = -1;
            for (int i = n; i >= 1; i--) {
                if ((s[i] - '0') % 2 == 1) {
                    pos = i;
                    break;
                } 
            }
            if (pos == -1) {
                puts("-1");
            }
            else {
                for (int i = 1; i <= pos; i++) {
                    printf("%c", s[i]);
                }
                puts("");
            }
        
        }
        else {
            int pos = -1;
            for (int i = n; i >= 1; i--) {
                if ((s[i] - '0') % 2 == 1) {
                    pos = i;
                    break;
                }
            }
            int pos1 = -1;
            for (int i = 1; i < pos; i++) {
                if ((s[i] - '0') % 2 == 1) {
                    pos1 = i;
                    break;
                }
            }
            if (pos == -1 || pos1 == -1) {
                puts("-1");
            }
            else {
                while (s[pos1 + 1] == '0') pos1++;
                if (pos1 >= pos) {
                    puts("-1");
                }
                else {
                    for (int i = pos1 + 1; i <= pos; i++) {
                        printf("%c", s[i]);
                    }
                    puts("");
                }
                
            }
        
        }
    }
    return 0;
}