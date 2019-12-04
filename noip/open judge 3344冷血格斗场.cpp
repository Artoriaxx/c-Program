#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;
map<int,int> mp;
int main()
{
	int n,id,pow;
	map<int,int>::iterator it,it2;
	mp[1000000000]=1;
	cin>>n;
	for(int i=2;i<=n+1;i++)
	{
		cin>>id>>pow;
		it=mp.find(pow);
		if(it==mp.end())
		{
			it=mp.lower_bound(pow);
		    if(it!=mp.end())
		    {
			    it2=it;
			    if(it2!=mp.begin())
			    {
				    it2--;
				    if(abs(pow-it2->first)<abs(it->first-pow))
				       {
				       	it=it2;
				       } 
			        else
			        {
			    	    if(abs(pow-it2->first)==abs(it->first-pow))
			    	    
			    		    it=(it2->second)<(it->second)?it2:it;
			    	    
			        }
			    }
		    }
		    else
		    {
		    	it--;
		    }
		    cout<<id<<" "<<it->second<<endl;
		    mp[pow]=id;
	    }
	    else
	    {
	    	printf("%d %d\n",id,mp[pow]);
	    	if(id<mp[pow])
	    	    mp[pow]=id;
	    }
	}
	return 0;
}
