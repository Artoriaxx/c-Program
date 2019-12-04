#include<cstdlib>
#include<iostream>
using namespace std;
char ch[6]={'A','B','C','D','E','F'};
void TurnData(int n,int m)
{
    int a[17],i,j,k=0;
    if (n<0) cout<<"-";      //负数的话，先输出负号再开始转
    j=abs(n);
    do
    {
        k++;    //用于统计转成a进制数后的总位数
        i=j%m;
        j/=m;
        a[k]=i;
    }while (j!=0);
    for (int h=k; h>=1; --h)
        if (a[h]<10) cout<<a[h];
        else cout<<ch[a[h]-10];
        cout<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    TurnData(n,m);
    return 0;
}


