#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 10, m = 3;
    srand(time(NULL));
    ifstream in("student.txt");
    ofstream out("score.txt");
    string id, tmp1, tmp2, tmp3;
    for (int i = 1; i <= n; i++) {
        in >> id >> tmp1 >> tmp2 >> tmp3;
        for (int j = 1; j <= m; j++) {
            int score = rand() % 41 + 60;//60~100 point
            out << id << " " << 10000 + j << " " << score << endl;
        }
    }
}