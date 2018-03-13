/**********************
author: yomi
date: 18.2.18
ps: 这是一道很麻烦的水题， 其实也不算麻烦， 但是容易出错， 至少对我来说是这样
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int m, n;
    int mark[1010];
    int real[1010];
    memset(real, 0, sizeof(real));
    char ans[1010][10];
    char res[1010][10];
    cin >> m >> n;
    int cntt = 0;
    int b, t[1010];
    char ch;
    int sum = 0;
    int flag = 1;
    for(int i=0; i<n; i++){
        cin >> mark[i] >> b >> t[i];
        sum += mark[i];
        for(int j=0; j<t[i]; j++){
            cin >> ans[i][j];
        }
    }
    int tt;
    int cnt;
    //memset(cnt, 0, sizeof(cnt));
    int cn = 0;
    int num[1010];
    int max_ = 0;
    int flag1[1010][100];
    for(int i=0; i<1010; i++){
        for(int j=0; j<100; j++){
            flag1[i][j] = 1;
        }
    }
    for(int i=0; i<m; i++){
        for(int k=0; k<n; k++){

            cin >> ch;
            cin >> tt;
            for(int j=0; j<tt; j++){
                cin >> res[k][j];
                if(res[k][j] != ans[k][j]){
                    flag = 0;
                    flag1[i][k] = 0;
                }
            }
            if(tt!=t[k]){
                flag = 0;
                flag1[i][k] = 0;
            }

            if(flag1[i][k]){
                real[i] += mark[k];
            }

            cin >> ch;
        }

    }
    int ji[1010];
    memset(ji, 0, sizeof(ji));
    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){
            if(flag1[j][i] == 0){
                ji[i]++;

            }
        }
        if(max_<=ji[i]){
            max_ = ji[i];
        }
    }
    for(int i=0; i<n; i++){
        if(max_ == ji[i])
        {
            num[cn++] = i+1;
        }
    }
    for(int i=0; i<m; i++){
        cout << real[i] << endl;
    }

    if(flag)
        cout << "Too simple";
    else{
        cout << max_ << ' ';
        for(int i=0; i<cn; i++){
            cout << num[i];
            if(i!=cn-1)
                cout << ' ';
        }
    }

    return 0;
}

/**
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
*/
