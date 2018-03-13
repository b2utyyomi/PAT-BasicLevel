/**********************
author: yomi
date: 18.2.18
ps:
此代码测试点1 ---->   WA
“爱丁顿数”E，即满足有E天骑车超过E英里的最大整数E。
测试点2, 3
4
3 3 3 3
2

测试点1过不去~
7
10 9 8 8 7 4 3
5

6
10 9 8 7 4 3
4

5
8 8 8 8 8
5

5
4 4 4 4 4
3

4
1 3 9 1
2
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

int cmp(int a, int b)
{
    return a>b;
}
int main()
{
    int n, a[100010];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n, cmp);
    int max_ = 0;
    int max1 = 0;
    int ans = 99999;
    int flag = 1;
    for(int i=0; i<n; i++){
        int t = i;
        if(t >= a[i] && i>0 && a[i] == a[i-1]-1){
            ans = min(a[i], t);
            max_ = max(max_, ans);
            flag = 0;
        }
        else if(t >= a[i] && i>0 && a[i]!=a[i-1] && flag){
            if(a[i-1] == t){
                max_ = a[i-1]-1;
                flag = 0;
                continue;
            }
            max_ = max(a[i], t);
            flag = 0;
        }

    }
    int min_ = 99999;
    min_ = min(a[n-1]-1, n);
    max_ = max(min_, max_);
    cout << max_;
    return 0;
}

/**
10
6 7 6 9 3 10 8 2 7 8

6

7
1 2 2 3 3 3 4

4
3 3 3 3

6
3 3 3 3 2 1

*/
