#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool a[100];
int main(){
	int first=1;
	memset(a,0,sizeof(a));
	for(int i=1;i<=100;i++)
	for(int j=1;j<=100;j++)
	if(j%i==0) a[j]=!a[j];
	for(int i=1;i<=100;i++)
	if(a[i]){
		if(first) first=0;
		else printf(" ");
		printf("%d",i); 
	}
	return 0;
} 
