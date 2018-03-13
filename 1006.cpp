/**********************
author: yomi
date: 18.1.9
ps:
**********************/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int a[10];
    memset(a, 0, sizeof(a));///用数组之前最好memset一下吧不然真容易出毛病
    cin >> n;
    int cnt = 0;
    while(n){
        a[cnt++] = n%10;
        n /= 10;
    }
    /// 0 1 2
    for(int i=0; i<a[2]; i++){
        cout << "B";
    }
    for(int i=0; i<a[1]; i++){
        cout << "S";
    }
    for(int i=0; i<a[0]; i++)
    cout << i+1;
    return 0;
}

