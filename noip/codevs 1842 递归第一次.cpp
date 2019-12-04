#include<iostream>
using namespace std;
int dfs(int x)
{
	return x>=0?5:dfs(x+1)+dfs(x+2)+1;
}
int main()
{
	int n;
	cin>>n;
	cout<<dfs(n);
	return 0;
}
