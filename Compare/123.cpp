/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2018-12-18 13:41:40
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-08 17:36:18
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
	int cnt = 10;
	while (1) {
		system("data.exe > data.txt");
		system("other.exe < data.txt > other.txt");
		system("my.exe < data.txt > my.txt");
		if (system("fc my.txt other.txt")) {
			break;
		}
    }
	return 0;
}