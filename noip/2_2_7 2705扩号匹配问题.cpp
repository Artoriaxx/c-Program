//http://noi.openjudge.cn/ch0202/2705/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char str[105];
int f[105]={0};
int len;
int dfs(int j)
{
	for(int i=j+1;i<len;i++)
	{
		if(f[i]==0)
		{
			switch(str[i])
			{
				case ')':f[i]=1;return 1;
				case '(':f[i]=dfs(i);break;
				default:f[i]=1;
			}
		}
	}
	return 2;
}
int main()
{
	
	while(cin.getline(str,101))
	{
		memset(f,0,sizeof(f));
		
		len=strlen(str);
		for(int i=0;i<len;i++)
		{
			if(f[i]==0)
			{
				switch(str[i])
				{
					case ')':f[i]=-1;break;
					case '(':f[i]=dfs(i);break;
					default:f[i]=1;
				}
			}
		}
		printf("%s\n",str);
		for(int i=0;i<len;i++)
		{
				switch(f[i])
				{
					case -1:cout<<'?';break;
					case 2:cout<<'$';break;
					default:cout<<' ';
				}
		}
		cout<<endl;
	}
	return 0;
}
