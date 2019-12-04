#include<iostream>
#include<cstdio>
using namespace std;
int x, y;
inline void exgcd(int a, int b){
	if(b == 0){
		x = 1, y = 0; return;
	}
	exgcd(b, a % b);
	int tmp = x;
	x = y;
	y = tmp - a / b * y;
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	exgcd(a, b);
	printf("%d", (x % b + b) % b);
} 
