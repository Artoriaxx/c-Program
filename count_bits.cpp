/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2019-11-15 16:05:19
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-03 10:24:34
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 2e5 + 50;
int main() {
    int x; scanf("%d", &x);
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0f0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f0f);
    x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
    x = (x & 0x0000ffff) + (x >> 16);
    printf("%d\n", x);
    return 0;
}
