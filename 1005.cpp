/**********************
author: yomi
date: 18.1.9
ps:
**********************/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n;
    int a[105];
    set<int>s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        int temp = a[i];
        while(temp!=1){
            if(temp%2){
                temp = (temp*3+1)/2;
            }
            else{
                temp /= 2;
            }
            for(int j=n-1; j>=0; j--){
                if(a[j] == temp){
                    s.insert(temp);

                }
            }

        }
    }
    int cnt1 = 0;
    for(int i=n-1; i>=0; i--){
        if(s.count(a[i])==0 ){
            cout << a[i];
            if(cnt1 < n-s.size()-1)
            cout << " ";

            cnt1++;
        }


    }
    return 0;
}
/*
6
3 5 6 7 8 11
*/
