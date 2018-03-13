/**********************
author: yomi
date: 18.2.5
ps:题目只保证第2行输入的文字串非空, so, 第1行不一定
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

int main()
{
    string s3 = "";
    char s1[100010];
    char s2[100010];
    //cin >> s1 >> s2;
    gets(s1);
    gets(s2);
    int flag = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i=0; i<len1; i++){
        if(s1[i] == '+'){
            flag = 1;
            break;
        }
    }
    for(int i=0; i<len2; i++){
        if(flag == 1 && s2[i]>='A' && s2[i] <= 'Z'){
            continue;
        }
        int j = 0;
        for(j=0; j<len1; j++){
            if(s2[i] == tolower(s1[j]) || s2[i] == s1[j]){
                break;
            }
        }
        if(j == len1){
            s3 += s2[i];
        }
    }
    cout <<s3;
    return 0;
}
