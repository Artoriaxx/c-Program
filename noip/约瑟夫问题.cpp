#include<iostream>
#include<cstring>
using namespace std;
int n,m,f,s,t;
bool a[101];
int main(){
	cin>>n>>m;
	cout<<endl;
	memset(a,0,sizeof(a));
	f=0;t=0;s=0;
	do{
		t++;
		if(t==n+1) t=1;
		if(a[t]==0) ++s;
		if(s==m){
			s=0;
			cout<<t<<" ";
			a[t]=1;
			f++;
		}
	}while(f!=n);
	return 0;
}
