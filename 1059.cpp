/**********************
author: yomi
date: 18.2.18
ps: 测试点2第一次没有过 原来是素数判断写错了
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool IsPrimer(int n)
{
    if(n == 2)
        return true;
    for(int i=2; i<sqrt(n)+1; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n;
    int id;
    int p[10010];
    memset(p, 0, sizeof(p));
    for(int i=1; i<=n; i++){
        cin >> id;
        p[id] = i;
    }
    cin >> m;
    bool visited[10010];
    memset(visited, false, sizeof(visited));
    for(int i=0; i<m; i++){
        cin >> id;
        printf("%04d", id);
        cout << ": ";
        if(p[id] == 0){
            cout << "Are you kidding?";
        }
        else{
            if(visited[id]){
                cout << "Checked";
                if(i!=m-1)
                    cout << endl;
                continue;
            }
            if(p[id] == 1){
                cout << "Mystery Award";
                visited[id] = true;
            }
            else if(IsPrimer(p[id])){
                cout << "Minion";
                visited[id] = true;
            }
            else{
                cout << "Chocolate";
                visited[id] = true;
            }

        }


        if(i!=m-1)
            cout << endl;

    }
    return 0;
}
/**
6
1111
6666
8888
1234
5555
0000
3
0000
8881
1110
*/
