#include<iostream>
using namespace std;
int magic[45][45];
int main(){
	int n;
	cin>>n;
	magic[1][(n+1)/2]=1;
	int nowx=1;int nowy=(n+1)/2;
	for(int i=2;i<=n*n;i++){
		if(nowx==1&&nowy!=n){
			magic[n][nowy+1]=i;
			nowx=n;nowy++;
		}
		else if(nowx!=1&&nowy==n){
			magic[nowx-1][1]=i;
			nowx--;nowy=1;
		}
		else if(nowx==1&&nowy==n){
			magic[nowx+1][nowy]=i;
			nowx++;
		}
		else if(nowx!=1&&nowy!=n){
			if(magic[nowx-1][nowy+1]==0){
				magic[nowx-1][nowy+1]=i;
				nowx--;nowy++;
			}
			else{
				nowx++;
				magic[nowx][nowy]=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<magic[i][j];
			if(j!=n) cout<<" ";
		}
		cout<<endl;
	}
}
