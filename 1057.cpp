/**********************
author: yomi
date: 18.2.12
ps:count函数第三个参数为单个字符。
**********************/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int sum = 0;
    for(int i=0; i<s.length(); i++){
        if(isalpha(s[i])){
            sum += tolower(s[i])-'0'-48;
        }
    }
    string ss = "";
    while(sum){
        ss += (sum%2)+'0';
        sum /= 2;
    }
    int a = count(ss.begin(), ss.end(), '1');
    int b = count(ss.begin(), ss.end(), '0');
    cout << b << ' ' << a;
    return 0;
}
