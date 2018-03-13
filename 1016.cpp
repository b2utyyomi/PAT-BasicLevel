/**********************
author: yomi
date: 18.1.24
ps:
**********************/
#include <iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include <cmath>
#include <cmath>
using namespace std;

long long int powe(int n)
{
    long long int ans = 1;
    for(int i=0; i<n; i++){
        ans = ans*10;
    }
    return ans;
}
long long int toInt(string s)
{
    long long int sum = 0;
    long long int cnt = 0;
    /// 66
    for(int i=s.length()-1; i>=0; i--){
        sum += (s[cnt++]-'0')*powe(i);
    }
    return sum;
}
int main()
{
    string a, b;
    char c, d;
    cin >> a >> c >> b >> d;
    string cc="",dd="" ;
    for(int i=0; i<a.length(); i++){
        if(a[i] == c){
            cc += c;
        }
    }
    for(int i=0; i<b.length(); i++){
        if(b[i] == d){
            dd += d;
        }
    }
    //cout << toInt(cc) << ' ' << toInt(dd) << endl;
    long long int aa = toInt(cc)+ toInt(dd);
    cout << aa << endl;
    return 0;
}


///3862767 6 13530293 3
