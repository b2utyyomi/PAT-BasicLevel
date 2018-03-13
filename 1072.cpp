/**********************
author: yomi
date: 18.2.21
ps:
**********************/
#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int m, n, t, d;
    string na;
    map<int, bool>vis;
    cin >> m >> n;
    int shou;
    for(int i=0; i<n; i++){
        cin >> shou;
        vis[shou] = true;
    }
    int cnt = 0;
    int cnt2 = 0;
    int a[1000];
    for(int i=0; i<m; i++){
        int cnt1 = 0;
        memset(a, 0, sizeof(a));
        cin >> na >> t;
        for(int j=0; j<t; j++){
            cin >> d;
            if(vis[d]){
                cnt++;
                a[cnt1++] = d;
            }

        }
        if(cnt1){
            cnt2++;
            cout<< na << ": ";
            for(int j=0; j<cnt1; j++){
                printf("%04d", a[j]);
                if(j!=cnt1-1)
                    cout << ' ';
            }
            cout << endl;
        }
    }
    cout << cnt2 << ' ' << cnt;
    return 0;
}

/**
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333

**/
