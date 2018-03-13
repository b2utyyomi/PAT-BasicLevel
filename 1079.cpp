/**********************
author: yomi
date: 18.2.23
ps: 最后一个测试点WA.
输入为不超过1000位的正整数。。。
WA的原因就是我把输入当成整型的了。所以说，不读五遍题，根本不够用。
**********************/
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

string tostring(int num)
{
    string s = "";
    while(num){
        s += num%10+'0';
        num /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
bool IsPal(string s)
{
    int i;
    for(i=0; i<s.length(); i++){
        if(s[i] != s[s.length()-i-1]){
            break;
        }
    }
    if(i == s.length()){
        return true;
    }
    return false;
}
int main()
{
    string s1;
    cin >> s1;
    int cnt = 0;
    while(1){
        if(cnt == 10){
            cout << "Not found in 10 iterations.";
            break;
        }
        if(IsPal(s1)){
            cout << s1 << " is a palindromic number.";
            break;
        }
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        /*int a = 0, b = 0, c = 0;
        istringstream is1(s1);
        is1 >> a;
        istringstream is2(s2);
        is2 >> b;
        c = a+b;
        cout << a << " + " << b << " = " << c << endl;*/
        ///下面就是所谓的高精度加法。。。
        string s3 = "";
        int len = s1.length();
        int jinwei = 0;
        for(int i=len-1; i>=0; i--){
            int a = s1[i]-'0';
            int b = s2[i]-'0';
            int c = a+b+jinwei;
            if(c == 0){
                s3 += '0';
                jinwei = 0;
            }
            else if(c/10 == 0){
                s3 += c%10+'0';
                jinwei = 0;
            }
            else if(c/10){
                s3 += c%10+'0';
                jinwei = 1;
            }
        }
        if(jinwei)
            s3 += jinwei+'0';
        reverse(s3.begin(), s3.end());
        cout << s1 << " + " << s2 << " = " << s3 << endl;
        s1 = s3;
        cnt++;
    }
    return 0;
}

/**
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
**/
