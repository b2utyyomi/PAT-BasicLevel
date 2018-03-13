/**********************
author: yomi
date: 18.1.29
ps:
**********************/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a[10];
    memset(a, 0, sizeof(a));
    for(int i=0; i<10; i++){
        cin >> a[i];
    }
    if(a[0] == 0){
        for(int i=1; i<10; i++){
            for(int j=0; j<a[i]; j++){
                cout << i;
            }
        }
    }
    else{
        for(int i=1; i<10; i++){
            if(a[i]!=0){
                cout << i;
                a[i]--;
                break;
            }
        }
        for(int i=0; i<10; i++){
            for(int j=0; j<a[i]; j++){
                cout << i;
            }
        }
    }
    return 0;
}
