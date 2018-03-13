/**********************
author: yomi
date: 18.2.17
ps: 又超时了， 其实这个题与之前的反转链表相似，暴力肯定超时
    可以利用i对应j而设个数组couple[i] = j, 改过之后还是超， cin改scanf解决问题
    scanf不能输入string呀, 改成char*还玩不明白， 果断改成int, 输出时控制一下格式就AC了。
**********************/
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>s3;
    set<int>s;
    map<int, int>couple;
    int a, b, c;
    for(int i=0; i<n; i++){
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++){

        scanf("%d", &c);
        s3.push_back(c);
    }

    for(int i=0; i<s3.size(); i++){
        int k = count(s3.begin(), s3.end(), couple[s3[i]]);
        if(k == 0)
            s.insert(s3[i]);
    }
    int cnt = 0;
    cout << s.size() << endl;
    for(set<int>::iterator iter=s.begin(); iter!=s.end(); ++iter){
        if(cnt)
            cout << ' ';
        printf("%05d", *iter);
        cnt++;
    }
    return 0;
}

/**
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
*/
