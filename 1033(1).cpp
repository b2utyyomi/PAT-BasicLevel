/**********************
author: yomi
date: 18.2.8
ps:题目保证第2行输入的文字串非空。
**********************/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i=0; i<s2.length(); i++){
        if(s1.find(toupper(s2[i]))!=-1||s1.find(tolower(s2[i]))!=-1){
            continue;
        }
        else if(s1.find("+")!=-1 && isupper(s2[i])){
            //cout << s2[i];
            continue;
        }
        cout << s2[i];
    }
    return 0;
}

/**
7+IE.
7_This_is_a_test.

**/
