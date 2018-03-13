/**********************
author: yomi
date: 18.2.7
ps: countº¯Êý³¬Ê±¡£
**********************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n, m, data;
    int a[100010], b[100010];
    memset(b, 0, sizeof(b));
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[a[i]]++;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> data;
        cout << b[data];
        if(i!=m-1)
            cout << ' ';
    }

    return 0;
}
