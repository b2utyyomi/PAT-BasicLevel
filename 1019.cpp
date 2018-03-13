/**********************
author: yomi
date: 18.1.26
ps:
error
9899
9998 - 8999 = 0999
0999 - 0999 = 0000
还是WA了几次，
一共就四位数，范围（0， 10000）
所以首先要想的就是输入一位数，两位数等的情况
**********************/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int powe(int n)
{
    int ans = 1;
    for(int i=0; i<n; i++){
        ans = ans * 10;
    }
    return ans;
}
int toint(string s)
{
    int sum = 0;
    int cnt = 0;
    for(int i=s.length()-1; i>=0; i--){
        sum += (s[cnt++]-'0')*powe(i);
    }
    return sum;
}
string tostring(int n)
{
    string s = "";
    while(n)
    {
        s += n%10+'0';
        n /= 10;
    }
    reverse(s.begin(), s.end());
    int cnt = 4-s.length();
    for(int i=0; i<cnt; i++){
        s = "0"+s;
    }
    return s;
}
int main()
{
    char s[100];
    string ss = "";
    cin >> s;
    sort(s, s+strlen(s));
    for(int i=0; i<strlen(s); i++){
        ss += s[i];
    }
    int cnt = 4-ss.length();
    for(int i=0; i<cnt; i++){
        ss = "0"+ss;
    }

    string ss1 = ss;
    reverse(ss.begin(), ss.end());
    int ans = -1;
    while(ans!=6174 && ans!=0){
        memset(s, 0, sizeof(s));
        ans = toint(ss)-toint(ss1);
        ///cout << ss << " - " << ss1 << " = " ;
        /*if(ans == 0)
            cout << "0000" << endl;
        else
            cout << ans << endl;*/
        printf("%04d - %04d = ", toint(ss), toint(ss1));
        printf("%04d\n", ans);
        ss = tostring(ans);
        for(int i=0; i<ss.length(); i++){
            s[i] = ss[i];
        }
        sort(s, s+strlen(s));
        ss = "";
        for(int i=0; i<strlen(s); i++){
            ss += s[i];
        }
        ss1 = ss;
        reverse(ss.begin(), ss.end());

    }

    return 0;
}
