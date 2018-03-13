/**********************
author: yomi
date: 18.2.13
ps: 随着时间的流逝，一切难题都将不再是难题，大前提是你要彻底弄懂它。
**********************/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct people
{
    string s;
    int h;
};

int cmp(people a, people b)
{
    if(a.h!=b.h)
        return a.h > b.h;
    else
        return a.s<b.s;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int t = n/k;
    int m = t+n%k;
    people a[10010], b[10010];
    for(int i=0; i<n; i++){
        cin >> a[i].s >> a[i].h;
    }
    sort(a, a+n, cmp);
    int cnt = 0;
    for(int i=0; i<k; i++){
        if(i == 0){
            int cnt1 = 0;
            for(int j=0; j<m; j++){
                b[j] = a[cnt++];
            }
            int tmp = 0;
            if(m%2 == 1)
                tmp = m-2;
            else
                tmp = m-1;
            for(int j=tmp; j>=1; j-=2){
                if(cnt1)
                    cout << ' ';
                cout << b[j].s;
                cnt1++;
            }

            for(int j=0; j<m; j+=2){
                if(cnt1)
                    cout << ' ';
                cout << b[j].s;
                cnt1++;
            }
            cout << endl;
        }
        else{
            int cnt1 = 0;
            for(int j=0; j<t; j++){
                b[j] = a[cnt++];
            }
            int tmp = 0;
            if(t%2 == 1)
                tmp = t-2;
            else
                tmp = t-1;
            for(int j=tmp; j>=1; j-=2){
                if(cnt1)
                    cout << ' ';
                cout << b[j].s;
                cnt1++;
            }

            for(int j=0; j<t; j+=2){
                if(cnt1)
                    cout << ' ';
                cout << b[j].s;
                cnt1++;
            }
            if(i!=k-1)
                cout << endl;
        }

    }


    return 0;
}
/*
9 2
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Job 175
Kob 172


*/
