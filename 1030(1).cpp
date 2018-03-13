/**********************
author: yomi
date: 18.2.6
ps:
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int a[100010];
    int n, p;
    cin >> n >> p;
    for(int i=0; i<n; i++){
        cin >>a[i];
    }
    sort(a, a+n);
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+ans; j<n; j++){///最多已经可以选择ans个数了，这一次从第i+ans
            if(a[j] > a[i]*p){///个数开始判断就可以了。
                break;
            }
            ans = max(ans, j-i+1);
        }
    }
    cout << ans;
    return 0;
}
