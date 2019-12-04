#include<bits/stdc++.h>
using namespace std;
char s1[100050];
int flag;
int main(){
	flag = true;
	gets(s1);
	int len = strlen(s1);
	for(int i = 0; i < strlen(s1); i++){
		char s = s1[i];
		if (s == '.'){
			flag = true;
			cout<<".";
		}
		else if (s == ' '){
			cout<<" ";
		}
		else {
			if (s >= 'a' && s <= 'z'){
				if (flag) cout<<char(s - 'a' + 'A');
				else cout<<s;
				flag = false;
			}
			else if(s >= 'A' && s <= 'Z'){
				if (flag) cout<<s;
				else cout<<char(s - 'A' + 'a');
				flag = false;
			}
		}
	}
	return 0;
}
