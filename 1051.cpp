/**********************
author: yomi
date: 18.2.20
ps:
坑点有二：
    都会导致测试点3  --->   WA
    一是不可以用float类型， 必须用double， 因为float精度不够，比大小不准。
    二是因为是保留两位小数， 那么-0.001, -0.00001等等等
    这些数输出将是-0.00，应该是0.00才对。思考一下，
    边界应该是-0.005，小于等于-0.005的，即-0.01， 才应该输出负号。
**********************/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    double r1, p1, r2, p2, a1, b1, a2, b2;
    cin >> r1 >> p1 >> r2 >> p2;
    a1 = r1*cos(p1);
    b1 = r1*sin(p1);
    a2 = r2*cos(p2);
    b2 = r2*sin(p2);
    //cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << endl;
    double c, d;
    c = a1*a2-b1*b2;
    d = a1*b2+a2*b1;

//    c = -0.005;
//    d = -0.0006;
    if(c<=-0.005)
        cout << '-';
    printf("%.2f", abs(c));
    if(d<=-0.005){
        cout << '-';
        printf("%.2fi", abs(d));
    }
    else
        printf("+%.2fi", abs(d));

    return 0;
}

/**
2.3 3.5 5.2 0.4

-0.005
**/
