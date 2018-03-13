/**********************
author: yomi
date: 18.2.5
ps:
**********************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    long long int p, data;
    std::ios::sync_with_stdio(false);
    //cin >> n >> p;
    scanf("%d%lld", &n,&p);
    vector<long long int>vec;
    for(int i=0; i<n; i++){
        //cin>> data;
        scanf("%lld", &data);
        vec.push_back(data);
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+ans; j<n; j++){
            if(vec[j] > vec[i]*p){
                break;
            }
            ans = max(ans, j-i+1);
        }

    }

    /***     TLE
    for(int j=0; j<vec.size(); j++){
        cnt1 = 1;
        for(int i=j+1; i<vec.size(); i++){
            if(vec[i] > vec[j]*p){
                break;
            }
            else
                cnt1++;
        }
        ans = max(ans, cnt1);
        if(vec.size()-j-1 < ans)
            break;

    }
    ***/
    printf("%d", ans);
    //cout << ans;
    /*  Ë¼Â·ÅÜÆ«
    int M, m;
    int max_ans = 0;
    for(int i=0; i<vec.size(); i++){
        for(int j=vec.size()-1; j>i; j--){
            M = *max_element(vec.begin()+i, vec.begin()+j+1);
            m = *min_element(vec.begin()+i, vec.begin()+j+1);
            if(M <= m*p){
                max_ans = max(max_ans, j-i+1);
            }
        }
    }
    cout << max_ans;
    */
    return 0;
}

/**
10 8
2 3 20 4 5 1 6 7 8 9
**/
