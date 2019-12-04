#include<cstdio>
int main()
{
	int temp,sum=0;
	FILE *fin,*fout;
	fin=fopen("in.txt","r");
	fout=fopen("out.txt","w");
	char name[10];
	while(fgets(name,9,fin)!=NULL)
	{
		fputs(name,fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
