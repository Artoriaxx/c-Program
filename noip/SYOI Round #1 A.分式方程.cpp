#include<iostream>
#define maxn 31622776
using namespace std;

int prime[maxn],primesize;
bool isprime[maxn];

void eularprime(int size = maxn){
	isprime[1] = true;
	for(int i = 2; i <= size; i++){
		if(!isprime[i]) prime[++primesize] = i;
		
		for(int j = 1; j <= primesize && i * prime[j] < size; j++){
			isprime[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

inline int decompose(long long n){
	long long ans = 1;
	for(int i = 1; i <= primesize && n > 1; i++){
		int now = 0;
		while(n % prime[i] == 0){
			now++;
			n /= prime[i];
		}
		ans *= now * 2 + 1;
	}
	if(n > 1) ans *= 2 + 1;
	return ans;
}

long long n;

int main(){
	int t;
	cin>>t;
	eularprime();
	while(t--){
		cin>>n;
		cout<<decompose(n)<<endl;
	}
	return 0;
} 
