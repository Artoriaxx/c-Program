#include<iostream>
#include<iomanip>
using namespace std;
int a[7][7];
int main()
{
for (int i=1; i<=6; ++i)	       //�������Ԫ��
for (int j=1; j<=6; ++j)
cin>>a[i][j];
for (int i=1; i<=6; ++i)	       //���ĶԽ�����Ԫ�ص�ֵ
for (int j=1; j<=6; ++j)
if ((i==j)||(i+j==7)) a[i][j]+=10;    //Ѱ�ҶԽ��ߵ�����
for (int i=1; i<=6; ++i)	       //���6��6�еľ���Ԫ��
{
for (int j=1; j<=6; ++j)
cout<<setw(5)<<a[i][j];
cout<<endl;
}
return 0;
}

