/**********************
author: yomi
date: 18.2.8
ps:
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int cnt[256];
    char ch;
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    for(int i=0; i<s.length(); i++){
        if(isalpha(s[i])){
            cnt[tolower(s[i])-'0']++;
        }
    }
    for(int i=0; i<256; i++){
        if(cnt[i] > ans){
            ans = cnt[i];
            ch = i+'0';
        }
    }

    cout << ch << ' ' << ans;
    return 0;
}
