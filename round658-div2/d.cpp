#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/rope>
using namespace __gnu_cxx;
/*
常用成员函数：
1.push_back(x)
2.在pos处插入：insert(pos,x)
3.从pos开始删除x个元素：erase(pos,x)
4.从pos开始换成x：replace(x)
5.从pos开始的len个元素换为x:copy(pos,len,x)
6.从pos开始提取x个元素：substr(pos,x)
7.访问第pos个元素:at(pos)/[pos]
*/
rope<int> T1, T2, T;
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        T1.push_back(i), T2.push_back(n - i + 1);
    int l, r;
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &l, &r);
        --l, --r;
        
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", T1[i]);
    return 0;
}