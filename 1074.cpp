/**********************
author: yomi
date: 18.2.21
ps: 脑袋似乎锈住了。。。
    不要忘记最高位的进位。
    还要考虑结果为0的情况
    0
    0
    0


    3
    9
    0


**********************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string table;
    string n1, n2;
    cin >> table >> n1 >> n2;
    int len1 = n1.length();
    int len2 = n2.length();
    int max_len = max(len1, len2);
    if(len1<max_len){
        int t = max_len-len1;
        for(int i=0; i<t; i++){
            n1 = "0"+n1;
        }
    }
    else if(len2<max_len){
        int t = max_len-len2;
        for(int i=0; i<t; i++){
            n2 = "0"+n2;
        }
    }
    //string ans = "";
    int ans[1010];
    int k;
    int cnt = 0;
    int j = table.length()-1;
    int jinwei = 0;
    int yu;
    for(int i=max_len-1; i>=0; i--){
        k = (n1[i]-'0')+(n2[i]-'0')+jinwei;
        //cout << k << endl;
        int r = table[j]-'0';
        //cout << r << endl;
        //cout <<r << endl;
        if(r == 0){
            r = 10;
        }
        if(k<r){
            yu = k%r;
            jinwei = 0;
        }
        else if(k == r){
            yu = 0;
            jinwei = 1;
        }
        else if(k>r){
            yu = k%r;
            jinwei = k/r;
        }
        ans[cnt++] = yu;
        j--;
    }
    int flag = 1;
    int r = table[0]-'0';
    if(r == 0)
        r = 10;
    while(jinwei){
        ans[cnt++] = jinwei%r;
        jinwei /= r;
        flag = 0;
    }

    for(int i=cnt-1; i>=0; i--){
        if(ans[i]!=0)
            break;
        cnt--;
    }
    for(int i=cnt-1; i>=0; i--){
        cout << ans[i];
        flag = 0;
    }
    if(flag)
        cout << "0";

    return 0;
}

/**
30527
06203
415
*/
