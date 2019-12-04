//http://noi.openjudge.cn/ch0202/1750/
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[7]={0};
char st[7]={0};
int f[7]={0};
int p=0,first=1,l;
void print()
{
		if(first) first =0;
		else cout<<endl; 
		printf("%s",st);
		
}
void push(int k)
{
	st[p]=s[k];
	p++;
	f[k]=1;
}
void pop()
{
	p--;
}
int sel(int k)
{
	int c=-1;
	for(int i=k;i<l;i++)
	{
		if(!f[i]) {	
			c=i;	
			break;
		}	
	}
	return c;
}
void dfs(int n)
{
	int k;
	if(n==0) print();
	else 
	{
		k=sel(0);
		while(k!=-1)
		{
			push(k);
			dfs(n-1);
			f[k]=0;
			pop();
			k++;
			k=sel(k);
		}
	}
}
int main()
{
	
	int n=0;
	scanf("%s",s);
	l=n=strlen(s);
	dfs(n);
    return 0;
}
