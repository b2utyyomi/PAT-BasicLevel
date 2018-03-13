/**********************
author: yomi
date: 18.1.21
ps:

**********************/
#include <iostream>
# include <string.h>
using namespace std;

int main()
{
    int m, n;
    int i = 0;
    int s[99999];
    while(cin >> m >> n){
        if(m == 0 && n == 0){
            s[i++] = 0;
            s[i++] = 0;
        }
        else if(m*n!=0){
            s[i++] = m*n;
            s[i++] = n-1;
        }
    }
    int t = 0;
    int tt = i;
    int flag = 0;
    for(int j=0; j<i; j++){
        if(s[j]!=0){
            flag = 1;
            break;
        }
    }
    if(flag){
        if(s[0] == 0 && s[1] == 0 && i>2){
            t = 2;
        }
        if(s[i-2] == 0 && s[i-1] == 0 && i>2){
            tt = i-2;
        }
        for(int j=t; j<tt; j++){
            if(j%2==0 && s[j]==0 && s[j+1]==0){
                j++;
                continue;
            }
            cout << s[j];
            if(j!=tt-1){
                cout << ' ';
            }
        }
    }
    else{
        cout << "0 0";
    }
    return 0;
}


//历史版本 22分
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int m, n;
//    int i = 0;
//    int flag = 0;
//    string s = "";
//    while(cin >> m >> n){
//        if(m == 0 && n == 0){
//            if(flag == 1){
//                s += ' ';
//                flag = 0;
//            }
//            s += "0 0";
//            flag = 1;
//        }
//        else if(m*n!=0){
//            if(flag == 1){
//                s += ' ';
//                flag = 0;
//            }
//            char c = m*n+'0';
//            cout << c << endl;
//            s += c;
//            s += ' ';
//            c = n-1+'0';
//            s += c;
//            flag = 1;
//        }
//        i++;
//    }
//    if(s[0] == '0' && s[2] == 0 && s.length()>3){
//        s = s.substr(3);
//        cout << s;
//    }
//    else{
//        cout << s;
//    }
//    return 0;
//}
//
