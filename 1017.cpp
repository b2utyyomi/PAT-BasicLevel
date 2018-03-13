/**********************
author: yomi
date: 18.1.25
ps:
**********************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int powe(int n)
{
    int sum = 1;
    for(int i=0; i<n; i++){
        sum *= 10;
    }
    return sum;
}
int toint(string s)
{
    int sum = 0;
    int cnt=0;
    for(int i=s.length()-1; i>=0; i--){
        sum += (s[cnt++]-'0')*powe(i);
    }
    return sum;
}
string tostring(int n)
{
    string s = ""       ;
    while(n){
        s += (n%10)+'0';
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    int n;
    string s;
    //while(1){
    cin >> s >> n;
    int flag1 = 0;
    string ans = "";
    string temp = "";
    int flag = 0;
    int res;
    int y = 0;
    int flag2 = 0;
    for(int i=0; i<s.length(); i++){/// 1002 2
        if(s[i] == '0' && flag == 0){
            ans += "0";
        }
        else if((s[i]-'0')<=n && i+1 <s.length() && flag == 0){
            if(i!=0 && s[i]-'0' < n)
                ans += "0";
            temp += "";
            temp += s[i];
            temp += s[i+1];
            int bcs = toint(temp);
            int sh = bcs/n;
            y = bcs%n;
            if(y==0)
                flag = 0;
            else
                flag = 1;
            if(sh != 0)
                ans += tostring(sh);
            else
                ans += "0";
            //s[i+1] = y+'0';
            i++;
            temp = "";
            temp+=tostring(y);
        }
        else if((s[i]-'0')<=n && i+1==s.length() && flag == 0){
            if((s[i]-'0') < n){
                ans += "0";
                flag2 = 1;
            }

            else{
                ans += "1";
                flag2 = 2;
            }

        }
        else if((s[i]-'0')>n && flag == 0){
            temp += "";
            temp += s[i];
            int bcs = toint(temp);
            int sh = bcs/n;
            y = bcs%n;
            if(y == 0)
                flag = 0;
            else
                flag = 1;
            ans += tostring(sh);
            temp = "";
            temp += tostring(y);
        }
        else if(flag == 1){
            temp += s[i];
            int bcs = toint(temp);
            int sh = bcs/n;
            y = bcs%n;
            if(y == 0)
                flag = 0;
            else
                flag = 1;
            ans += tostring(sh);
            temp = "";
            temp += tostring(y);
        }

        if(flag2 == 1)
            res = s[s.length()-1]-'0';
        else
            res = y;
    }
    if(flag1 == 0)
        cout << ans << " " << res;
    //}
    return 0;
}
/// 123456789050987654321 7

/**
201201199 2


**/
