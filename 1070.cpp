/**********************
author: yomi
date: 18.2.20
ps: 这是一道贪心题，越早加入的绳子对折次数越多，所以
越长的绳子应该越晚加入。
但是 关于计算对折长度 可以是(旧长度+新长度)/2 也可以是
(旧长度/2) + (新长度/2) 另外 由于要求向下取整， 所以第二种
所求得的结果是小于第一种
综上， 应使用(旧长度+新长度)/2来计算。
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int a[10010];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int max_ = 0;
    int sum = a[0];
    for(int i=1; i<n; i++){
        sum = (sum+a[i])/2;

    }
    cout << sum;
    return 0;
}

/**
8
10 15 12 3 4 13 1 15

**/
