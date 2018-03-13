/**********************
author: yomi
date: 18.2.4
ps:
**********************/
#include <iostream>
#include <vector>
using namespace std;

int r[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
///M£º1 0 X 9 8 7 6 5 4 3 2
char M[11] = {'1', '0',  'X',  '9', '8', '7', '6', '5', '4', '3', '2'};
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    string s;
    vector<string>vec;
    for(int i=0; i<n; i++){
        cin>> s;
        int sum = 0;
        for(int i=0; i<17; i++){
            sum += r[i]*(s[i]-'0');
        }
        sum %= 11;
        if(s[17] == M[sum]){
            cnt++;
        }
        else{
            vec.push_back(s);
        }

    }
    if(cnt == n)
        cout << "All passed";
    else{
        for(int i=0; i<vec.size(); i++){
            cout << vec[i];
            if(i!=vec.size()-1){
                cout << endl;
            }
        }
    }

    return 0;
}
