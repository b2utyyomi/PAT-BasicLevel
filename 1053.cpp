/**********************
author: yomi
date: 18.2.18
ps:
**********************/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, t;
    double e, r;
    double ke, bi;
    int D;
    int cnt = 0;
    int ke_cnt = 0;
    int bi_cnt = 0;
    cin >> n >> e  >> D;
    for(int i=0; i<n; i++){
        cin >> t;
        cnt = 0;
        for(int j=0; j<t; j++){
            cin >> r;
            if(r < e){
                cnt++;
            }
        }
        if(t>D && cnt>t/2){
            bi_cnt++;
        }
        else if(cnt>t/2){
            //cout << i << endl;
            ke_cnt++;
        }

    }
    //cout << ke_cnt << ' ' << bi_cnt <<  endl;
    ke = ke_cnt*1.0/n*100;
    bi = bi_cnt*1.0/n*100;
    printf("%.1f%% %.1f%%", ke, bi);
    return 0;
}
/**
5 0.5 10
6 0.3 0.4 0.5 0.2 0.8 0.6
10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
5 0.4 0.3 0.5 0.1 0.7
11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1

*/
