/**********************
author: yomi
date: 18.2.11
ps:������һ��i��ߣ�����i������,��i���е����ж��ǰ���i�����У���i+1��,
������һ��i�ұߣ�����i������,��i���е����ж��ǰ���i�����У���n-i����
�������������Ҳͬ���ǰ���i�����У�����һ���а�����i�����еĸ���Ϊ(i+1)*(n-i)

��float ���������Ե�WA
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

   /* ��֪TLE ƫҪTLE
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
