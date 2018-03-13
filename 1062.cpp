/**********************
author: yomi
date: 18.2.17
ps:坑点就是给出的两个分数没有大小顺序
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    return gcd(b, a%b);
}
int main()
{
    int a, b, c, d, k; /// a/b   c/d
    scanf("%d/%d %d/%d %d", &a, &b, &c, &d, &k);
    int bei = b*d/gcd(b, d);
    a = a*(bei/b);
    c = c*(bei/d);
    int bei1 = bei*k/gcd(bei, k);
    a = a*(bei1/bei);
    c = c*(bei1/bei);
    bei = bei1;
    if(a > c)
        swap(a, c);
    int cnt = 0;
    for(int i=a+1; i<c; i++){
        ///   i/bei1  k      70/180     117/180

        if(bei/gcd(bei, i)==k){
            if(cnt)
                cout << ' ';
            cout << i/gcd(bei, i) << '/' << k;
            cnt++;
        }
    }
    return 0;
}
