/**********************
author: yomi
date: 18.2.13
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int correct[100];
    int stu[100];
    int ans[100][100];
    int cnt = 0;
    int s, p;
    cin >> s >> p;
    for(int i=0; i<p; i++){
        cin >> correct[i];
    }
    for(int i=0; i<p; i++){
        cin >> stu[i];
    }
    for(int i=0; i<s; i++){
        for(int j=0; j<p; j++)
            cin >> ans[i][j];
    }
    for(int i=0; i<s; i++){
        cnt = 0;
        for(int j=0; j<p; j++){
            if(ans[i][j] == stu[j])
                cnt = cnt+correct[j];
        }
        cout << cnt;
        if(i!=s-1)
            cout << endl;
    }
    return 0;
}
