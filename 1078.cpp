/**********************
author: yomi
date: 18.2.21
ps: 我又自己编题了。。。
    空格也是计数的。。。
    孩子， 你这样只会使题变复杂还拿不到分啊。
**********************/
#include <iostream>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    char ch;
    string s;
    cin >> ch;
    getchar();
    getline(cin, s);
    if(ch == 'C'){//TTTTThhiiiis isssss a   tesssst CAaaa as
        int cnt = 0;
        s+="1";
        for(int i=0; i<s.length(); i++){
//            if(isalpha(s[i]) && i == 0){ 自己编题的下场
//                cnt++;
//            }
//            if(!isalpha(s[i])){
//                //cout << s[i] << ' ' << s[i-1] << ' ' << cnt << endl;
//
//                if(cnt>1 && i-1>=0 && isalpha(s[i-1])){
//                    cout << cnt << s[i-1];
//                }
//                else if(cnt == 1 && i-1>=0 && isalpha(s[i-1])){
//                    //cout << isalpha(s[i-1]); 天哪 这个BUG找了n久 我说s咋输不出来
//                    cout << s[i-1];
//                }
//                cout << s[i];
//                cnt = 0;
//
//            }
//            else if(isalpha(s[i])&& i+1<s.length() && s[i] == s[i-1]){
//                cnt++;
//            }
//            else if(isalpha(s[i]) && i>=1){
//                if(cnt>1){
//                    cout << cnt;
//                }
//                cout << s[i-1];
//                cnt = 1;
//            }

            if(i == 0)
                cnt++;
            if(i+1<s.length() && s[i] == s[i-1]){
                cnt++;
            }
            else if(i>=1){
                if(cnt>1){
                    cout << cnt;
                }
                cout << s[i-1];
                cnt = 1;
            }


        }
    }
    else if(ch == 'D'){
        string ss = "";
        int flag = 0;
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i]) && isdigit(s[i+1]) && i+1<s.length()){
                ss += s[i];
                ss += s[i+1];
                flag = 1;
                i++;
            }
            else if(isdigit(s[i]) && !isdigit(s[i+1]) && i+1<s.length()){
                ss += s[i];
                istringstream is;
                is.str(ss);
                int t;
                is >> t;
                for(int j=0; j<t; j++){
                    cout << s[i+1];
                }
                ss = "";
                i++;
            }
            else if(isdigit(s[i]) && i+1<s.length() && !isdigit(s[i+1])){
                int t = s[i]-'0';
                for(int j=0; j<t; j++){
                    cout << s[i+1];
                }
                ss = "";
                i++;
            }
            else if(ss!=""){
                istringstream is;
                is.str(ss);
                int t;
                is >> t;
                for(int j=0; j<t; j++){
                    cout << s[i];
                }
                ss = "";
            }
            else{
                cout << s[i];
                ss = "";
            }
        }
    }
    return 0;
}
