/**********************
author: yomi
date: 18.2.11
ps:正常编码必超时。
1 3 2 4 5
1 2 3 4 5
按照样例研究一下可以发现一个规律
排序之后顺序不变的是主元， 然后。。。就重在参与了。。。
2 4 3 1 5
1 2 3 4 5
这种情况下 3并不符合要求
没必要用set的 因为已经排过序了
**********************/
#include <iostream>
#include <algorithm>
#include <string>
#include<set>
using namespace std;

int main()
{
    int a[100010], b[100010];
    set<int>s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);
    int cnt = 0;
    //int s[100010];
    int ans = 0;

    for(int i=0; i<n; i++){

        if(a[i] == b[i] && b[i]>ans){

            s.insert(a[i]);

        }
        ans = max(ans, b[i]);
    }
    cout << s.size() << endl;
    for(set<int>::iterator iter=s.begin(); iter!=s.end(); ++iter){
        if(*iter == *s.rbegin()){
            cout << *iter;
            break;
        }
        cout << *iter << ' ';
    }
    cout << endl;//测试点2
    return 0;
}
