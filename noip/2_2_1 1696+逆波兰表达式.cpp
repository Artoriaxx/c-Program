//http://noi.openjudge.cn/ch0202/1696/
#include<iostream>
#include<cstdio>
#include<cstring>
#include <stdlib.h>
using namespace std;
char s[1010];
char t[50];
double temp;
char *p;
int j=0;
double dfs()
{
	switch(*p)
	{
		case '+':p++;return (dfs() + dfs());
		case '-':p++;return (dfs() - dfs());
		case '*':p++;return (dfs() * dfs());
		case '/':p++;return (dfs() / dfs());
		case 0	:
		case ' ':if(strlen(t)>0)
				 {
				 	p++;
				 	temp=atof(t);
				 	memset(t,0,sizeof(t));
				 	j=0;
				 	return temp;	
		         }
		         else
		         {
		         	p++;
		         	return dfs();
		         }
		         
		default:t[j++]=*p++;return dfs();
	}
}
int main()
{
	cin.getline(s,1010);
	p=s;
	if(strlen(s)!=0) printf("%f\n", dfs());
	return 0;
}
