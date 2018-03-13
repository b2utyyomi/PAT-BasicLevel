/**********************
author: yomi
date: 18.2.8
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    long long int g1, s1, k1, g2, s2, k2;
    scanf("%lld.%lld.%lld", &g1, &s1, &k1);
    scanf("%lld.%lld.%lld", &g2, &s2, &k2);
    long long int sum1 = 0, sum2 = 0, ans = 0;
    sum1 = k1+29*s1+29*17*g1;
    sum2 = k2+29*s2+29*17*g2;
    ans = sum1-sum2;
    if(ans > 0)
        cout << "-";
    long long int g3, s3, k3;
    g3 = abs(ans)/29/17;
    s3 = (abs(ans)-g3*29*17)/29;
    k3 = (abs(ans)-g3*29*17-s3*29);
    cout << g3 << "." << s3 << "." << k3;
    return 0;
}
///10.16.27 14.1.28
