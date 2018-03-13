/**********************
author: yomi
date: 18.1.6
ps:
**********************/
#include <iostream>
#include <string>
using namespace std;

bool tell(string s)
{
    for(int i=0; i<s.length(); i++){
        if(s[i]!='P'&&s[i]!='A'&&s[i]!='T')
            return false;
    }
    int pos_p = 0, pos_t = 0;
    int cnt1 = 0, cnt2 = 0;
    int cnt_p = 0;
    int cnt_t = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'P'){
            cnt_p++;
            pos_p = i;
        }

        else if(s[i] == 'T'){
            cnt_t++;
            pos_t = i;
        }

    }
    if(cnt_p!=1 || cnt_t!=1)
        return false;
    int cnt_a=0;
    for(int i=pos_p+1; i<pos_t; i++){
        if(s[i]!='A')
            return false;
        cnt_a++;
    }
    for(int i=0; i<pos_p; i++){
        if(s[i]!='A')
            return false;
        cnt1++;
    }
    for(int i=pos_t+1; i<s.length(); i++){
        if(s[i]!='A')
            return false;
        cnt2++;
    }
    if(cnt_a == 1){
        if(cnt1!=cnt2)
            return false;
        return true;
    }
    if(cnt_a==0){
        return false;
    }
    if(cnt1 == 0 && cnt2 ==0 && cnt_a != 0)
        return true;
    if(cnt2 / cnt1 == cnt_a){///写一堆正确的串 找到这个规律就AC了
        return true;
    }
    return false;
}
int main()
{
    int T;
    string s;
    cin >> T;
    while(T--){
        cin >> s;
        if(tell(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}
