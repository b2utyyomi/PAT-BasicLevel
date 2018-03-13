/**********************
author: yomi
date: 18.2.21
ps: 与反转链表大同小异
**********************/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int start, n, k;
    cin >> start >> n >> k;

    int addr;
    int a[100010], next[100010], d[100010], e[100010];
    for(int i=0; i<n; i++){
        cin >> addr;
        cin >> a[addr] >> next[addr];
    }

    int cnt = 0;
    addr = start;
    while(addr!=-1){
        d[cnt++] = addr;
        addr = next[addr];
    }
    int cnt1 = 0;
    for(int i=0; i<cnt; i++){
        if(a[d[i]] < 0){
            e[cnt1++] = d[i];
        }
    }
    for(int i=0; i<cnt; i++){
        if(a[d[i]]>=0 && a[d[i]]<=k){
            e[cnt1++] = d[i];
        }
    }
    for(int i=0; i<cnt; i++){
        if(a[d[i]]>k){
            e[cnt1++] = d[i];
        }
    }
    for(int i=0; i<cnt1-1; i++){
        printf("%05d %d %05d\n", e[i], a[e[i]], e[i+1]);
    }
    printf("%05d %d -1", e[cnt1-1], a[e[cnt1-1]]);
    return 0;
}

/**
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
*/
