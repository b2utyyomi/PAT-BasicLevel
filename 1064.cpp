/**********************
author: yomi
date: 18.2.17
ps:
**********************/
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    int n;
    string s;
    set<int>ss;
    ss.clear();
    cin >> n;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = 0;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            sum += s[j]-'0';
        }
        ss.insert(sum);
    }
    cout << ss.size() << endl;
    int cnt = 0;
    for(set<int>::iterator iter=ss.begin(); iter!=ss.end(); ++iter){
        if(cnt)
            cout << ' ';
        cout << *iter;
        cnt++;
    }
    return 0;
}

/**
8
123 899 51 998 27 33 36 12
*/
