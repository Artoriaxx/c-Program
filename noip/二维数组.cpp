#include<iostream>
#include<iomanip>
using namespace std;
int a[7][7];
int main()
{
for (int i=1; i<=6; ++i)	       //输入矩阵元素
for (int j=1; j<=6; ++j)
cin>>a[i][j];
for (int i=1; i<=6; ++i)	       //更改对角线上元素的值
for (int j=1; j<=6; ++j)
if ((i==j)||(i+j==7)) a[i][j]+=10;    //寻找对角线的特征
for (int i=1; i<=6; ++i)	       //输出6行6列的矩阵元素
{
for (int j=1; j<=6; ++j)
cout<<setw(5)<<a[i][j];
cout<<endl;
}
return 0;
}

