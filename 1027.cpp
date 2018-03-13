/**********************
author: yomi
date: 18.2.1
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int n;
    char ch;
    cin >> n >> ch;
    int sum = -1;
    int cnt = 0;
    for(int i=1; i<999; i+=2){
        sum += 2*i;
        if(sum > n){
            sum -= 2*i;
            break;
        }
        cnt++;
    }
    for(int i=cnt; i>=1; i--){
        for(int j=0; j<cnt-i; j++){
            cout << " ";
        }
        for(int j=0; j<2*i-1; j++){
            cout << ch;
        }
        cout << endl;
    }
    for(int i=2; i<=cnt; i++){
        for(int j=0; j<cnt-i; j++){
            cout << " ";
        }

        for(int j=0; j<2*i-1; j++){
            cout << ch;
        }
        cout << endl;
    }
    //cout << cnt << endl;
    cout << n-sum;
    return 0;
}

/*
19 *
*****
 ***
  *
 ***
*****
2
*/
