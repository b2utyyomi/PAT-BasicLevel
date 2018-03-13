/**********************
author: yomi
date: 18.1.9
ps:
**********************/
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n == 1 || n == 0)
        return false;
    if(n == 2)
        return true;
    for(int i=2;i<sqrt(n)+1; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(isPrime(i) &&isPrime(i+2) && !isPrime(i+1) && (i+2<=n)){ ///这个出界判定不要忘记
            cnt++;
        }
    }
    cout <<cnt;
    return 0;
}
