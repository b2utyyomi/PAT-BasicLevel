#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    string str;
    map<string, int> mapp;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        cin >> str;
        if (mapp[str] == 1) s++;
        if (i == s && mapp[str] == 0) {
            cout << "cnt: " << i << endl;
            mapp[str] = 1;
            cout << "out:   ";
            cout << str << endl;
            flag = true;
            s += n;
        }
    }
    if (flag == false) cout << "Keep going...";
    return 0;
}
