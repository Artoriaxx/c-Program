#include<cstdlib>
#include<iostream>
using namespace std;
char ch[6]={'A','B','C','D','E','F'};
void TurnData(int n,int a)
{
int x[17],i,j,k=0;
cout<<n<<" turn into "<<a<<"  : "<<endl;
if (n<0) cout<<'-';      //�����Ļ�������������ٿ�ʼת
j=abs(n);
do
{
           k++;    //����ͳ��ת��a�����������λ��
           i=j%a;
           j/=a;
           x[k]=i;
}while (j!=0);
for (int h=k; h>=1; --h)
if (x[h]<10) cout<<x[h];
else  cout<<ch[x[h]-10];
cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    TurnData(n,2);      //nת��2������
    TurnData(n,8);      //nת��8������
    TurnData(n,16);    //nת��16������
    return 0;
}


