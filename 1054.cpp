/**********************
author: yomi
date: 18.2.18
ps: 测试点2死活过不去。。。
    一个多小时一直在想我是不是遗漏了什么不属于数字的情况。。。
    知道真相才发现，原来我距离AC只有一步之遥。
    1 number 不是 1 numbers...
**********************/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    float sum = 0.0;
    int cnt = 0;
    while(T--){
        string s;
        float d;
        cin >> s;
        int flag = 0;
        int tt = 0;
        tt = count(s.begin(), s.end(), '.');
        if(tt>1){
            cout << "ERROR: "<< s <<" is not a legal number" << endl;
            continue;
        }
        for(int i=0; i<s.length(); i++){
            if(i == 0){

                if(s[0] == '-'){
                    if(s[1] == '.'){
                        flag = 1;
                        cout << "ERROR: "<< s <<" is not a legal number" << endl;
                        break;
                    }
                    continue;
                }


            }
            if((s[i]<'0' || s[i]>'9') && s[i]!='.'){
                flag = 1;
                cout << "ERROR: "<< s <<" is not a legal number" << endl;
                break;
            }


        }
        if(flag)
            continue;
        if(tt == 1){
            //cout << "tmp:" << s.find('.') << endl;
            string tmp = s.substr(s.find('.')+1, s.length());
            if(tmp.length()>2){
                cout << "ERROR: "<< s <<" is not a legal number" << endl;
                continue;
            }
        }
        istringstream is;
        is.str(s);
        is >> d;
        if(d>1000 || d<-1000){
            cout << "ERROR: "<< s <<" is not a legal number" << endl;
            continue;
        }
        sum += d;
        cnt++;
    }
    if(cnt == 1){
        float average = sum/cnt;
        cout << "The average of " << cnt << " number is ";
        printf("%.2f", average);
    }
    else if(cnt){
        float average = sum/cnt;
        cout << "The average of " << cnt << " numbers is ";
        printf("%.2f", average);
    }
    else{
        cout << "The average of " << cnt << " numbers is Undefined";
    }


    return 0;
}
/**
3
5 -3.2. aaa

8
-1000 1000.99 aaa -999.99 -2.3.4 -.123 2.35 .99
*/
