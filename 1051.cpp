/**********************
author: yomi
date: 18.2.20
ps:
�ӵ��ж���
    ���ᵼ�²��Ե�3  --->   WA
    һ�ǲ�������float���ͣ� ������double�� ��Ϊfloat���Ȳ������ȴ�С��׼��
    ������Ϊ�Ǳ�����λС���� ��ô-0.001, -0.00001�ȵȵ�
    ��Щ���������-0.00��Ӧ����0.00�Ŷԡ�˼��һ�£�
    �߽�Ӧ����-0.005��С�ڵ���-0.005�ģ���-0.01�� ��Ӧ��������š�
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
