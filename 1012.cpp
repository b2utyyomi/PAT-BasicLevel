/**********************
author: yomi
date: 18.1.10
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[1010];
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int flag1 = 1;
    int flag2 = 1;
    int flag3 = 1;
    int flag = 1;
    int t = -1;
    int b = 0;
    int c = 0;
    int d = 0;
    float e = 0;
    int sum = 0;
    int cnt = 0;
    int f = 0;
    for(int i=0; i<n; i++){
        if(a[i]%5==0 && a[i]%2 == 0){
            b += a[i];
            flag1 = 0;
        }
        else if(a[i]%5==1 && flag2 == 1){
            c += a[i];
            flag2 = 0;
            flag = 0;
        }
        else if(a[i]%5==1 && flag2 == 0){
            c += a[i]*t;
            flag2 = 1;
            flag = 0;
        }
        else if(a[i]%5 == 2)
            d++;
        else if(a[i]%5==3){
            sum += a[i];
            cnt++;
        }
        else if(a[i]%5==4){
            f = max(f, a[i]);
            flag3 = 0;
        }
    }
    e = sum*1.0/cnt;
    if(flag1)
        cout << "N ";
    else
        cout << b << ' ';
    if(flag)
        cout << "N ";
    else
        cout << c << ' ';
    if(d == 0)
        cout << "N ";
    else
        cout << d << ' ';
    if(sum == 0)
        cout << "N ";
    else
        printf("%.1f ", e);
    if(flag3)
        cout << "N";
    else
        cout << f;

    return 0;
}
