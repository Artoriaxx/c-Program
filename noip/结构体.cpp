#include<iostream>
#include<cstdio>
using namespace std;
struct STUDENT
{
	char num[10];
	char name[10];
	float grade[2];	
}stu[2];
int main()
{
	int i;
	float sum=0;
	for(i=0;i<2;i++)
	{
		cin>>stu[i].num>>stu[i].name;
		for(int j=0;j<2;j++)
		    scanf("%f",&stu[i].grade[j]);	
	}
	for(i=0;i<2;i++)
	{
		sum=0;
		cout<<stu[i].num<<" "<<stu[i].name<<" ";
		for(int j=0;j<2;j++)
		{
			printf("%.2f ",stu[i].grade[j]);
			sum+=stu[i].grade[j];
		}
		cout<<sum/2<<endl;
	}
	return 0;
}
