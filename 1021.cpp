/**********************
author: yomi
date: 18.1.25
ps:写麻烦了，只用一个数组就能实现
**********************/
#include <iostream>
#include<string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
struct number
{
    int n;
    int cnt;
}num[1010];
int cmp(number a, number b)
{
    return a.n<b.n;
}
int main()
{
    int n;
    memset(num, 0, sizeof(num));
    string s;
    cin >> s;
    int cn = 0;
    for(int i=0; i<s.length(); i++){
        num[s[i]-'0'].n = s[i]-'0';
        num[s[i]-'0'].cnt++;
    }
    sort(num, num+maxn, cmp);
    for(int i=0; i<maxn; i++){
        if(num[i].cnt != 0){
            cout << num[i].n << ":" << num[i].cnt << endl;
        }
    }

    return 0;
}
/// 100311
