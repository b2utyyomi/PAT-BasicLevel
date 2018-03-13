/**********************
author: yomi
date: 18.2.2
ps:
**********************/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    vector<char>s;
    string s1, s2;
    cin >> s1 >> s2;

    sort(s1.begin(), s1.end());
    s1.erase(unique(s1.begin(), s1.end()), s1.end());
    sort(s2.begin(), s2.end());
    s2.erase(unique(s2.begin(), s2.end()), s2.end());

    cout << s1 << endl << s2 << endl;
    /*for(int i=0; i<s1.length(); i++){
        if(s2.find(toupper(s1[i]))==-1 && s2.find(tolower(s1[i]))==-1 && find(s.begin(), s.end(), toupper(s1[i]))==s.end()){
            s.push_back(toupper(s1[i]));
        }
    }
    for(vector<char>::iterator iter=s.begin(); iter!=s.end(); ++iter){
        cout << *iter ;
    }*/
    return 0;
}

/*
7_This_is_a_test_78
_hs_s_a_es_8
78T_aehist
8_aehs

7TI
*/
