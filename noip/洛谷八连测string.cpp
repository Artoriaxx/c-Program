#include<bits/stdc++.h>
using namespace std;
char s1[100050], s2[100050];
int vis[100];
struct node{
    int begin, end, tmp, k;
}c[100050];
struct node1{
    int begin, end;
}c1[100050];
int cnt, cnt1;
int main(){
//	freopen("s.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%s%s", s1, s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        bool flag = 0; bool flag1 = 0;
        memset(c, 0, sizeof(c));
        memset(c1, 0, sizeof(c1));
        memset(vis, 0, sizeof(vis));//注意清空 
        cnt = cnt1 = 0;
        for (int i = 0; i < len1; i++){
        	if (s1[i] == '*'){
                c[cnt].tmp = 1; 
                c[cnt].k++;
                c[cnt].end = i;//注意更新 
				continue;
            } 
        	int a = s1[i] - '0';
            if (!vis[a]){
            	c[++cnt].begin = i;
            	c[cnt].end = i;
            	memset(vis, 0, sizeof(vis));
            	vis[a] = 1;
            }
            else {
            	c[cnt].end = i;
            	continue;
        	}
        }
        flag = 0, flag1 = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < len2; i++){
        	int a = s2[i] - '0';
            if (!vis[a]) {
            	c1[++cnt1].begin = i;
            	c1[cnt1].end = i;
            	memset(vis, 0, sizeof(vis));
            	vis[a] = 1;
            }
            else {
            	c1[cnt1].end = i;
            	continue;
        	}
        }
        bool flag2 = 0;
        if (cnt1 != cnt){
            cout << "No" << endl;
            flag2 = 1;
            continue;
        }
        for (int i = 1; i <= cnt; i++){
            if (s1[c[i].begin] != s2[c1[i].begin]){
                cout << "No" << endl;
                flag2 = 1;
                break;
            }
            else {
                if(c[i].end - c[i].begin - c[i].k == c1[i].end - c1[i].begin){ //注意减去*数 
                    continue;
                }
                else if (c[i].end - c[i].begin - c[i].k < c1[i].end - c1[i].begin){
                	if (c[i].tmp == 1){
                		continue;
                	}
                }
            }
            cout << "No" << endl;
            flag2 = 1;
            break;
        }
        if (!flag2) cout << "Yes" << endl;//注意控制输出个数 
    }
    return 0;
}
