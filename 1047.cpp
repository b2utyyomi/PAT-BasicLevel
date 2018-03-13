/**********************
author: yomi
date: 18.2.9
ps:
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int cmp(int a, int b)
{
    return a>b;
}
int main()
{
    int T;
    cin >> T;
    int a[1001];
    memset(a, 0, sizeof(a));
    int d1, d2;
    int mark;
    while(T--){
        scanf("%d-%d", &d1, &d2);
        scanf("%d", &mark);
        a[d1]+= mark;
    }
    int  max = 0;
    int num;
    for(int i=1; i<=1000; i++){
        if(a[i] > max){
            num = i;
            max = a[i];
        }
    }
    cout << num << " " << max;
    return 0;
}
/**
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
*/
