/**********************
author: yomi
date: 18.1.6
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int number;
    cin >> number;
    int cnt = 0;
    while(number!=1){
        if(number % 2){
            number = (3*number+1)/2;
        }
        else{
            number = number/2;
        }
        cnt++;

    }
    cout << cnt << endl;
    return 0;
}
