/**********************
author: yomi
date: 18.1.9
ps: n���ܴ���m��һ����ӣ�����˵ѭ����λ��λ�����ܴ��������С������
**********************/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{



    //*****************����ʹ�����������*****************//
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
