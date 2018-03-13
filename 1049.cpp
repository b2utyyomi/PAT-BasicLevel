/**********************
author: yomi
date: 18.2.11
ps:对于任一个i左边（包括i）的数,与i所夹的数列都是包含i的数列，有i+1个,
对于任一个i右边（包括i）的数,与i所夹的数列都是包含i的数列，有n-i个，
两者再组合起来也同样是包含i的数列，所以一共有包含有i的数列的个数为(i+1)*(n-i)

用float 后两个测试点WA
**********************/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    double a;
    //float sum1 = 0.0;
    double sum2 = 0.0;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        sum2 += a*(i+1)*(n-i)*1.0;
    }

   /* 明知TLE 偏要TLE
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum1 = 0;
            for(int k = i; k<=j; k++){
                sum1 += a[k];
            }
            sum2 += sum1;
        }
    }
    */
    printf("%.2f", sum2);
    return 0;
}
