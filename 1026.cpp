/**********************
author: yomi
date: 18.2.1
ps:
**********************/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int a, b;
    cin >> a >> b;
    long long int time = b-a;
    double ti = time*1.0/100;
    int h = (int)ti/3600;
    int m = ((int)ti-h*3600)/60;
    int s = ((int)ti-h*3600)%60;
    int t = s+m*60+h*3600;
//    cout << ti << endl;
//    cout << t << endl;
    if(ti - t*1.0>=0.5)///Àƒ…·ŒÂ»Î
        s = s+1;
    printf("%02d:", h);
    printf("%02d:", m);
    printf("%02d", s);
    //cout << h << ":" << m << ":" << s ;

    return 0;
}
