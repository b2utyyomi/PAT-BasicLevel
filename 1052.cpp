/**********************
author: yomi
date: 18.2.20
ps: 首先死在了转义字符上。。。
    然后又死在了边界控制上，就是kidding的条件。不能只顾右而不思左啊！
**********************/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string hand, eyes, mouth;
    getline(cin, hand);
    getline(cin, eyes);
    getline(cin, mouth);
    string h[100], e[100], m[100];
    int from, to;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int t = 0;
    for(int i=0; i<hand.length(); i++){
        if(hand[i] == '['){
            from = i;
            t = 0;
        }
        if(hand[i] == ']'){
            to = i;
            //cout << from << ' ' << t << endl;
            h[cnt1++] = hand.substr(from+1, t-1);
        }
        t++;
    }
    for(int i=0; i<eyes.length(); i++){
        if(eyes[i] == '['){
            from = i;
            t = 0;
        }
        if(eyes[i] == ']'){
            to = i;
            //cout << from << ' ' << t << endl;
            e[cnt2++] = eyes.substr(from+1, t-1);
        }
        t++;
    }
    for(int i=0; i<mouth.length(); i++){
        if(mouth[i] == '['){
            from = i;
            t = 0;
        }
        if(mouth[i] == ']'){
            to = i;
            //cout << from << ' ' << t << endl;
            m[cnt3++] = mouth.substr(from+1, t-1);
        }
        t++;
    }
    int n;
    cin >> n;
    int d[5];
    int flag = 0;
    for(int i=0; i<n; i++){
            flag = 0;;
        for(int j=0; j<5; j++){
            cin >> d[j];
            if(j == 0 || j == 4){
                if(d[j]-1>=cnt1|| d[j]-1<0){
                    cout << "Are you kidding me? @\\\/@";
                    if(i!=n-1)
                        cout << endl;
                    flag = 1;
                    break;
                }

            }
            else if(j == 1 || j == 3){
                if(d[j]-1>=cnt2|| d[j]-1<0){
                    flag = 1;
                    cout << "Are you kidding me? @\\\/@";
                    if(i!=n-1)
                        cout << endl;
                    break;
                }

            }

            else{
                if(d[j]-1>=cnt3 || d[j]-1<0){
                    flag = 1;
                    cout << "Are you kidding me? @\\\/@";
                    if(i!=n-1)
                        cout << endl;
                    break;
                }
            }
        }

        if(flag)
            continue;
        for(int j=0; j<5; j++){
            if(j == 0){
                cout << h[d[j]-1];
                cout << "(";
            }
            else if(j == 4){
                cout << ")";
                cout << h[d[j]-1];
            }
            else if(j == 1 || j == 3){
                cout << e[d[j]-1];
            }

            else{
                cout << m[d[j]-1];
            }

        }
        if(i!=n-1)
        cout << endl;
    }
    return 0;
}

/**
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
*/
