#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int f[250][250],maxl;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		maxl=0;
	    memset(f,0,sizeof(f));
		for(int i=a.length()-1;i>=0;i--)
		{
			for(int j=b.length()-1;j>=0;j--)
			{
				if(a[i]==b[j])
				{
					f[i][j]=max(f[i+1][j+1]+1,max(f[i+1][j],f[i][j+1]));
				}
				if(a[i]!=b[j])
				{
					f[i][j]=max(f[i+1][j],f[i][j+1]);
				}
				maxl=max(maxl,f[i][j]);
			}
	    }
		cout<<maxl<<endl;
	}
	return 0;
}
