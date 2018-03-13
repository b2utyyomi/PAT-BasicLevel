/**********************
author: yomi
date: 18.2.6
ps:
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int start, n, k;
    cin >> start >> n >> k;
    int a[100010], next[100010], b[100010], d[100010];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(next, 0, sizeof(next));
    int addr;
    for(int i=0; i<n; i++){
        cin >> addr;
        cin >> b[addr];
        cin >> next[addr];
    }
    int cnt = 0;
    addr = start;
    while(addr!=-1){
        d[cnt++] = addr;
        addr = next[addr];
    }

    for(int i=0; i<cnt/k; i++){
        reverse(d+i*k, d+i*k+k);
    }
    for(int i=0; i<cnt-1; i++){
        printf("%05d %d %05d\n", d[i], b[d[i]], d[i+1]);
    }
    printf("%05d %d -1", d[cnt-1], b[d[cnt-1]]);
    return 0;
}
/*
00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218


*/
