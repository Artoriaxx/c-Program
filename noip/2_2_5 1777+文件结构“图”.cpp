//http://noi.openjudge.cn/ch0202/1777/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string s,st;

void printsj(int n)
{
	printf("|     ");
}
void print(int n,string *f,int j)
{
		//if(n==1)
//		{
//			printf("DATA SET %d:\n",x);
//			printf("ROOT\n");
//		}
//		
//		else
	
	for(int k=0;k<j;k++)
	{
		for(int t=n-1;t>0;t--)
		{
			printf("|     ");
		}
		cout<<*(f+k)<<endl;
	}
}
int dfs(int n,int l)
{

	
	string f[31];
	int i=0,j=0,r;//j表示当前目录有多少个文件，r表示文件名或者文件夹名右侧换行符的位置 
	do
	{
		
		switch(s[l])
		{
			case 'd':r=s.find('\n',l);
					 for(int k=n;k>0;k--)
					 	{
					 		printf("|     ");
					 	}
					 cout<<s.substr(l,r-l)<<endl;
					 l=dfs(n+1,r+1)+2;
					 break;
			case 'f':r=s.find('\n',l);
					 f[j++]=s.substr(l,r-l);
					 l=r+1;
					 break;
			case '*':break;
			case ']':sort(f,f+j);
					 print(n,f,j);
					 return l;
			case '#':break;
		}	
	}
	while(s[l]!='*');
	if(s[l]=='*')
	{
		sort(f,f+j);
		print(n,f,j);
	}
	return l;
}

int main()
{
	int x=1,n=1,l=1;//l表示当前访问字符的位置 

	while(s[l]!='#') 
	{
		{//将输入全部写入字符串S中 
			s="";
			st="";
			getline(cin,st);
			if(st[0]=='#') break;
			
			while(st[0]!='*')
			{
				if(!st.length()) {
					getline(cin,st);
					continue;	
				}			
				s=s+'\n'+st;
				getline(cin,st);
			}
			s+="\n*";
		}
		
		printf("DATA SET %d:\n",x);
		printf("ROOT\n");
		dfs(n,l);
		cout<<endl;
		l=1;
		n=1;
		x++;
	}	
	return 0;
}
