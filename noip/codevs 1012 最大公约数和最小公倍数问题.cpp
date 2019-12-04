//两个数的乘积等于最大公约数与最小公倍数的乘积 
#include<iostream>
#include<cmath> 
using namespace std;
int gcd(int n, int m){
	return n % m == 0 ? m : gcd(m, n % m);
}
int main(){ 
	int x, y;
	cin >> x >> y;
	int mul = x * y, ans = 0;
	for (int i = 1; i <= sqrt(mul); i++)
	{
		if(mul % i == 0 && gcd(i, mul / i) == x) ans++;
	}
	cout << 2 * ans;
	return 0;
}

