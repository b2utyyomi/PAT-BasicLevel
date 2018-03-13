/**********************
author: yomi
date: 18.2.28
ps:
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[101], b[101];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    int j;
    for(int i=1; i<n; i++){
        if(b[i]<b[i-1]){
            j = i;
            break;
        }
    }
    int t;
    for(t=j; t<n; t++){
        if(b[t] != a[t]){
            break;
        }
    }
    if(t == n){
        cout << "Insertion sort" << endl;
        sort(b, b+j+1);
        for(int i=0; i<n; i++){
        cout << b[i];
        if(i!=n-1)
            cout << ' ';
        }
    }
    else{
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        while(flag){
            flag = 0;
            for(int i=0; i<n; i++){
                if(a[i]!=b[i]){
                    flag = 1;
                }
            }
            k = 2*k;
            for(int i=0; i<n/k; i++){
                sort(a+i*k, a+(i+1)*k);
            }
            sort(a+n/k*k, a+n);
        }
        for(int i=0; i<n; i++){
            cout << a[i];
            if(i!=n-1)
                cout << ' ';
        }
    }

    return 0;
}

/**
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0


10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
**/








