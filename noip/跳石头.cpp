#include<iostream>
using namespace std;
const int maxn=50005;
int a[maxn],n,m,ans;
int check(int x)
{
	int sum=0,last=0;
	for(int i=1;i<=n;i++)
	if(a[i]-last<x)
	{
		sum+=1;
		continue;
	}
	else last=a[i];
	if(sum>m) return 0;
	else return 1;
}
int main()
{
	int L,R,MID,left;
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	n+=1;
	a[n]=L;R=L;
	ans=left=0;
	while(left<=R)
	{
		MID=left+(R-left)/2;
	    if(check(MID))
	    {
	    	ans=MID;
		    left=MID+1;
	    }
	    else R=MID-1;
	}
	cout<<ans<<endl;
	return 0;
}
