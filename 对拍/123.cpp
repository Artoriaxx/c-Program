#include<bits/stdc++.h>
using namespace std;
int main() {
	while (1) {
		system("data.exe > data.txt");
		system("other.exe < data.txt > other.txt");
		system("my.exe < data.txt > my.txt");
		if (system("fc my.txt other.txt")) break;
    }
	return 0;
}