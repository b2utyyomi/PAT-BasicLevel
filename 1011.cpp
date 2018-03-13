/**********************
author: yomi
date: 18.1.
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int T;
    int i=1;
    cin >> T;
    while(T--){
        long long int a, b, c;
        cin >> a >> b >> c;
        cout << "Case #"<< i++ << ": ";
        if(a+b>c)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
/*
Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/
