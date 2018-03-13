/**********************
author: yomi
date: 18.1.10
ps:
**********************/
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
    if(n == 2)
        return true;
    for(int i=2; i<sqrt(n)+1; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    int m, n;
    cin >> m >> n;
    int a[10010];
    int cnt = 0;
    int cnt1 = 0;
    for(int i=2; i<1000000; i++){
        if(cnt>n)
            break;
        if(isPrime(i)){
            if(cnt>=m-1 && cnt<n){
                a[cnt1++] = i;

            }
            cnt++;

        }

    }
    for(int i=0; i<cnt1; i++){
        cout << a[i];
        if(i%10 == 9)
            cout << endl;
        else if(i!=cnt1-1)
            cout << " ";
    }

    return 0;
}
