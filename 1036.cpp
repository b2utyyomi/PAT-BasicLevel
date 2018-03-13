/**********************
author: yomi
date: 18.2.3
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int n;
    char ch;
    cin >> n >> ch;
    float m = n*1.0/2;
    int mm = n/2;
    if(m-mm*1.0 >= 0.5){
        mm++;
    }
    for(int i=0; i<mm; i++){
        if(i == 0 || i == mm-1){
            for(int j=0; j<n; j++){
                cout << ch;
            }
        }
        else{
            for(int j=0; j<n; j++){
                if(j == 0 || j == n-1)
                    cout << ch;
                else
                    cout << ' ';
            }
        }
        if(i!=mm-1)
            cout << endl;
    }
    return 0;
}
