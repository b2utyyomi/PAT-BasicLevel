/**********************
author: yomi
date: 18.1.9
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    char ch[100];
    stringstream i;
    string a[100];
    string b;
    int cnt = 0;
    gets(ch);
    i << ch;
    while(i >> b){
        a[cnt++] = b;
    }

    for(int i=cnt-1; i>=0; i--){
        cout << a[i];
        if(i!=0)
            cout << ' ';
    }

    return 0;
}
