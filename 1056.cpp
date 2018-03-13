/**********************
author: yomi
date: 18.2.11
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10];
    int sum = 0;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum += a[i]*10+a[j];
            sum += a[i]+10*a[j];
        }
    }
    cout << sum;
    return 0;
}
