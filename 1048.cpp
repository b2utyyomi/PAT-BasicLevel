/**********************
author: yomi
date: 18.2.10
ps:WA了好长一会儿，主要是题意理解错误， 傻乎乎的把前导零给去掉了
吃一堑 长一智 看来AC率不高的题一定得当心
这个题，首先是补位，让s1,s2长度相等，然后对奇数位和偶数位分别做处理就行了
仔细想想，毕竟是加密，如果去掉了前导零，那么以后就不知道前面一共有几个零了，
那还怎么解密呀
**********************/
#include <iostream>
#include <string>
#include <cmath>
#include<sstream>
using namespace std;

int main()
{
    //while(1){
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s2.length();
    int len2 = s1.length();
    int c = abs(len1-len2);
    if(s1.length()>s2.length()){
        for(int i=0; i<c; i++){
            s2 = "0"+s2;
        }
    }
    else{
        for(int i=0; i<c; i++){
            s1 = "0"+s1;
        }
    }
//    cout << c << endl;
//
//    cout << s1 << ' ' << s2 << endl;
    int t = 1;
    for(int i=s2.length()-1; i>=0; i--,t++){
        if(t%2 == 0){
            int tmp =  (s2[i]-'0') - (s1[i]-'0') ;
            if(tmp < 0)
                tmp += 10;
            s2[i] = tmp+'0';
        }
        else{
            int tmp = ((s1[i]-'0') + (s2[i]-'0'))%13;
            //cout << tmp << endl;
            if(tmp == 10){
                s2[i] = 'J';
            }
            else if(tmp == 11){
                s2[i] = 'Q';
            }
            else if(tmp == 12){
                s2[i] = 'K';
            }
            else{
                s2[i] = tmp+'0';
            }

        }

    }

    cout << s2;
   /* 无需去掉前导零
   stringstream is;
    is.str(s2);
    int a=0;
    string ss;
    if(s2[0]>='0' && s2[0]<='9'){
        is >> a;
        is >> ss;
    }

    else
        is >> ss;
    if(a==0 && ss.length() == 0)
        cout << a;
    else if(a>0)
      cout << a;
    if(ss.length()!=0)
        cout << ss;
    }*/
    //cout << s2;


    return 0;
}

///**
//1234567 368782971
//
//**/
