/**********************
author: yomi
date: 18.2.8
ps:
**********************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1;
    cin >> s1;
    int P = 0, A = 0, T = 0, s = 0, e = 0, t = 0;
    int PP = 0, AA = 0, TT = 0, ss = 0, ee = 0, tt = 0;
    for(int i=0; i<s1.length(); i++){
        if(s1[i] == 'P'){
            P++;
        }
        else if(s1[i] == 'A'){
            A++;
        }
        else if(s1[i] == 'T'){
            T++;
        }
        else if(s1[i] == 'e'){
            e++;
        }
        else if(s1[i] == 's'){
            s++;
        }
        else if(s1[i] == 't'){
            t++;
        }
    }
    while(PP<P || AA<A || TT<T || ss < s||ee<e||tt<t){
        if(PP<P){
            cout << "P";
        }
        if(AA<A){
            cout << "A";
        }
        if(TT<T){
            cout << "T";
        }
        if(ee<e){
            cout << "e";
        }
        if(ss <s){
            cout << "s";
        }
        if(tt<t){
            cout << "t";
        }
        PP++,AA++,TT++,ss++,ee++,tt++;
    }

    return 0;
}
