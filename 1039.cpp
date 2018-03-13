/**********************
author: yomi
date: 18.2.6
ps:
**********************/
#include <iostream>
#include <cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s1, s2;
    int n = 0;
    int flag = 0;
    int num[1010], zhu[1010];
    memset(num, 0, sizeof(num));
    memset(zhu, 0, sizeof(zhu));
    cin >> s1 >> s2;
    int cnt = 0;
    for(int i=0; i<s2.length(); i++){
        num[s2[i]]++;
    }
    for(int i=0; i<s1.length(); i++){
        zhu[s1[i]]++;
    }
    int que = 0;
    for(int i=0; i<256; i++){
        if(num[i] && zhu[i] && num[i] <= zhu[i]){
            cnt += num[i];
        }
        else if(num[i]){
            flag = 1;
            int temp = num[i]-zhu[i];
            que += temp;
        }
    }
    n = abs(s1.length()-cnt);
    if(flag == 0){
        cout << "Yes" << " " << n;
    }
    else{
        cout << "No" << ' ' << que;
    }
    return 0;
}

/**

ppRYYGrrYBR2258
YrR8RrY

**/
