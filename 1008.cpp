/**********************
author: yomi
date: 18.1.9
ps: n可能大于m是一个大坑，就是说循环移位的位数可能大于数组大小！！！
**********************/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{



    //*****************不许使用另外的数组*****************//
    int m, n;
    int a[201];
    memset(a, 0, sizeof(a));
    cin >> m >> n;
    for(int i=0; i<m; i++){
        cin >> a[i];
    }
    int temp = n%m;
    for(int i=m-1; i>=0; i--){
        a[i+temp] = a[i];
    }
    int cnt = 0;
    for(int i=m; i<m+temp; i++){
        a[cnt++] = a[i];
    }
    for(int i=0; i<m; i++){
        cout << a[i];
        if(i!=m-1)
            cout <<  ' ';
    }



    return 0;
}
