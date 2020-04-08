#include<time.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<vector>
inline int read() {
    char c; int ans = 0; int flag = 1;
    while (!isdigit(c = getchar()));
    if (c == '-') flag = -1; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * flag;
}
using namespace std;
int *a,k,len;
class Solve{
	public:
		int ans;
		Solve(int *a,int len,int k)
		{
			ans=select(a,len,k);
		}
		int select_(int *V,int len,int k)
				{
			if(len==1)
			{
				return V[0];
			}
			int temp=(len-1)/5+1;
			for(int i=0;i<temp-1;i++) sort(V+i*5,V+(i+1)*5);
			sort(V+(temp-1)*5,V+len);
			int *tempV;tempV=(int*)malloc(temp*sizeof(int));
			for(int i=0;i<temp-1;i++) tempV[i]=V[i*5+2];
			tempV[temp-1]=(V[(temp-1)*5+(((len-1)%5+1)/2)]);
			int tempk=temp/2;
			int x=select_(tempV,temp,tempk);
			if(x==-1) x=tempV[temp-1];
			free(tempV);
			int *S,*L,cots=0,cotl=0,cotx=1;
			S=(int* )malloc(len*sizeof(int));
			L=(int* )malloc(len*sizeof(int));
			for(int i=0;i<len;i++)
			if(V[i]<x) 
			{
				S[cots++]=V[i];
			}
			else if(V[i]==x)
			{
				x++;
			}
			else if (V[i]>x)
			{
				L[cotl++]=V[i];	
			}
			if(cotx+cotl<=cots)for(int i=0;i<cotx;i++)L[cotl++]=x;else
			if(cotx+cots<=cotl)for(int i=0;i<cotx;i++)S[cots++]=x;
			else
			{
				int temp_=abs(cots-cotl);
				if(cots>cotl)for(int i=0;i<temp_;i++)L[cotl++]=x;
				else for(int i=0;i<temp_;i++)S[cots++]=x;
				cotx-=temp_;
				temp_=cotx/2;
				for(int i=0;i<temp_;i++)L[cotl++]=x;
				temp_=cotx-temp_;
				for(int i=0;i<temp_;i++)S[cots++]=x;
			}
			if(k>cots) return select_(L,cotl,k-cots);
			else return select_(S,cots,k);
		}
		int select(int *V,int len,int &k)
		{
			if(len==1)
			{
				k--;return V[0];
			}
			int temp=(len-1)/5+1;
			for(int i=0;i<temp-1;i++) sort(V+i*5,V+(i+1)*5);
			sort(V+(temp-1)*5,V+len);
			int *tempV;tempV=(int*)malloc(temp*sizeof(int));
			for(int i=0;i<temp-1;i++) tempV[i]=V[i*5+2];
			tempV[temp-1]=(V[(temp-1)*5+(((len-1)%5+1)/2)]);
			int tempk=temp/2;
			int x=select_(tempV,temp,tempk);
			if(x==-1) x=tempV[temp-1];
			free(tempV);
			int *S,*L,cots=0,cotl=0;
			S=(int* )malloc(len*sizeof(int));
			L=(int* )malloc(len*sizeof(int));
			for(int i=0;i<len;i++)
			if(V[i]<x) 
			{
				S[cots++]=V[i];
			}
			else if (V[i]>x)
			{
				L[cotl++]=V[i];	
			}
			if(cotl>cots)S[cots++]=x;
			else L[cotl++]=x;
			free(V);
			if(k&&cots)
			x=select(S,cots,k);
			if(k&&cotl)
			x=select(L,cotl,k);
			if(len==500) 
			{
				x++;x--;
			}
			if(k)x=-1;
			return x;
		}
};
void init()
{
	len=read();k=read();
	a=(int*)malloc((len+5)*sizeof(int));
	for(int i=0;i<len;i++)a[i]=read();
}
int main()
{
	freopen("data.txt", "r", stdin);
//	clock_t start=clock();
	std::ios::sync_with_stdio(false);
	init();
	cout<<Solve(a,len,k).ans<<endl;
//	clock_t finish=clock();
//	cout<<finish-start<<endl;
	return 0;
}
