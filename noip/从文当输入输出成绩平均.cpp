#include<iostream>
#include<cstdio>
using namespace std;
const int N=2;
const int M=2;
double goal[2];
struct  STUDENT{
	char num[10];
	char name[10];
	float grade[M];
};
STUDENT stu[N];
int main()
{
	FILE *fin,*fout;
	fin=fopen("in.txt","r");
	fout=fopen("out.txt","w");
	int i,j,k=0,p;
	float sum=0;
	for(i=0;i<N;i++)
	{
		fscanf(fin,"%s%s",stu[i].num,stu[i].name);
		for(j=0;j<M;j++)
		{
			fscanf(fin,"%f",&stu[i].grade[j]);
		}
	}
	for(i=0;i<N;i++)
	{
			sum=0;
		for(j=0;j<M;j++)
		{
			sum+=stu[i].grade[j];
		}
		goal[i]=sum;
	
	}
	if(goal[0]<goal[1])
	{
		p=goal[0];
		goal[0]=goal[1];
		goal[1]=p;
		for(i=1;i>=0;i--)
	{
		fprintf(fout,"%s %s ",stu[i].num,stu[i].name);
		for(j=0;j<M;j++)
		{
			fprintf(fout,"%.2f ",stu[i].grade[j]);
		}
		fprintf(fout,"%.2f\n",goal[k++]/2);
	}
	}
	else	
	{for(i=0;i<N;i++)
	{
		fprintf(fout,"%s %s ",stu[i].num,stu[i].name);
		for(j=0;j<M;j++)
		{
			fprintf(fout,"%.2f ",stu[i].grade[j]);
		}
		fprintf(fout,"%.2f\n",goal[i]/2);
	}
}
	fclose(fin);
	fclose(fout);
	return 0;
}
