/**********************
author: yomi
date: 18.2.21
ps:
**********************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin>> n;
    char ch;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cin >>  s;
            if(s[2] == 'T'){
                ch = s[0];
            }
        }
        if(ch == 'A')
            cout << "1";
        else if(ch == 'B')
            cout << "2";
        else if(ch == 'C')
            cout << "3";
        else if(ch == 'D')
            cout << "4";

    }
    return 0;
}

/**
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
**/
