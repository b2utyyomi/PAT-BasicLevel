/**********************
author: yomi
date: 18.1.
ps:
**********************/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,data;
    int max1 = 0, max2 = 0;
    int a[100010];
    memset(a, 0, sizeof(a));
    cin >> n;
    int j;
    for(int i=0; i<n; i++){
        cin >> j >> data;
        a[j] += data;
        max1 = max(max1, j);
    }
    int t = 1;
    for(int i=1; i<=max1; i++){
        if(a[i] > max2){
            max2 = a[i];
            t = i;
        }

    }
    cout << t << ' ' << max2;
    return 0;
}
