/**********************
author: yomi
date: 18.2.19
ps: ����WA�� ����һ�� ���˺�������ʱ������
    һ���ﵽ���������������������֮��
    Ӧ�����������ģ� ��������һ�������ʱ��
    ����AC�ʲ��ߣ��������Ҳ�Ǵ��������˰�
    �ָ��˸�ʽ ��ȻWA
    �������cin�ĳ���getline Ȼ��AC�� T^T
    ��ʵ������������ ������Ŀ��˵�������ո�
    Tab֮��ģ� ���Թ���ûд�������������ش�
**********************/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string right;
    int n;
    string in;
    cin >> right >> n;
    int cnt = 0;
    int flag = 1;
    getchar();
    while(1){
        getline(cin, in);
        if(in == "#")
            break;

        if(right == in && flag){
//            if(cnt)
//            cout << endl;    �������Ƹ�ʽ���� �޷����
            cout << "Welcome in" << endl;
            flag = 0;
        }
        if(flag){
//            if(cnt)
//            cout << endl;
            cout << "Wrong password: " << in << endl;
        }
        if(cnt == n-1 && flag){
//            if(cnt)
//            cout << endl;
            cout << "Account locked" << endl;
            flag = 0;
        }

        cnt++;
    }
    return 0;
}

/**
Correct%pw 5
aaa
c
dd
bbb
Correct%pb
Correct@PW
Correct%pb
lll
lll
#

cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
aaa
try again
#





**/
