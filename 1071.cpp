/**********************
author: yomi
date: 18.2.21
ps: shui
**********************/
#include <iostream>

using namespace std;

int main()
{
    int start, n, n1, b, t, n2;
    int flag1 = 0;
    cin >> start >> n;
    for(int i=0; i<n; i++){
        int flag = 0;
        cin >> n1 >> b >> t >> n2;
        if(flag1 == 1)
            continue;
        if(t>start){
            cout << "Not enough tokens.  Total = " << start << "." << endl;
            continue;
        }
        if(n2<n1 && b == 0){
            start += t;
            flag = 1;
        }
        else if(n2>n1 && b == 1){
            start+=t;
            flag = 1;
        }
        else{
            start -= t;
            flag  = 0;
        }

        if(flag){
            cout << "Win " << t << "!  Total = " << start << "." << endl;
        }
        else{
            cout << "Lose " << t << ".  Total = " << start << "." << endl;
        }
        if(start <=0){
            cout << "Game Over." << endl;
            flag1 = 1;
        }

    }
    return 0;
}

/**
100 4
8 0 100 2
3 1 50 1
5 1 200 6
7 0 200 8

**/
