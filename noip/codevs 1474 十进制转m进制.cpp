#include<cstdlib>
#include<iostream>
using namespace std;
char ch[6]={'A','B','C','D','E','F'};
void TurnData(int n,int m)
{
    int a[17],i,j,k=0;
    if (n<0) cout<<"-";      //�����Ļ�������������ٿ�ʼת
    j=abs(n);
    do
    {
        k++;    //����ͳ��ת��a�����������λ��
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


