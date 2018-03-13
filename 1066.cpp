/**********************
author: yomi
date: 18.2.17
ps:
**********************/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int m, n;
    int k, t, new_, d;
    int a[510][510];
    cin >> m >> n >> k >> t >> new_;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> d;
            if(d>=k && d<=t){
                d = new_;
            }
            a[i][j] = d;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%03d", a[i][j]);
            if(j!=n-1)
                cout << ' ';
        }
        if(i!=m-1)
            cout << endl;

    }
    return 0;
}

/**
3 5 100 150 0
3 189 254 101 119
150 233 151 99 100
88 123 149 0 255
*/
