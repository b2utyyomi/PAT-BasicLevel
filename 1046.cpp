/**********************
author: yomi
date: 18.2.9
ps:
**********************/
#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0;
    int T;
    int c, d, e, f;
    cin >> T;
    while(T--){
        cin >> c >> d >> e >> f;
        if(d == c+e && f == c+e){
            continue;
        }
        else if(d!=c+e && f!=c+e){
            continue;
        }

        else if(d == c+e){
            a++;
        }
        else if(f == c+e){
            b++;
        }
    }
    cout << b << ' ' << a;

    return 0;
}
