#include<iostream>
using namespace std;
char a[1100][1100];//�ö�ά����һ��һ������ 
int main()
{
	int i=1;
	while(cin>>a[i])
	{
		i++;
	}
	for(int j=i-1;j>=2;j--)
	{
		cout<<a[j]<<" ";
	}
	cout<<a[1];
	return 0;
}
