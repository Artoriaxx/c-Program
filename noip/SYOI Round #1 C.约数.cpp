#include<iostream>
#include<cmath>
using namespace std;
long long ans;
int main(){
	long long n,k;
	cin>>n>>k;
	long long cnt = 0;
	long long s =  (long long) sqrt(n);
	for(long long i = 1; i <= s; i++){
		if(n % i == 0){
			cnt++;
			if(cnt == k){
				cout<<i;
				return 0;
		    }
		}
		
	}
	int vis = 0;
	if(s * s == n) vis = 1;
	for(long long i = s - vis; i >= 1; i--){
		if(n % i == 0){
			cnt++;
			if(cnt == k){
				cout<<n / i;
				return 0;
			}
		}	
	}
	cout<<"-1";
	return 0;
} 
