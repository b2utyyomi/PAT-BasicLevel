/**********************
author: yomi
date: 18.1.29
ps:WA��һ��,��sum=0ʱ��û�ж�����ջ���������ģ�
����ʲô��û�������
**********************/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    long long int a, b;
    int c;
    stack<long long int>s;
    while(!s.empty())
        s.pop();
    cin >> a >> b >> c;
    int sum = a+b;
    while(sum){
        s.push(sum%c);
        sum /= c;
    }
    int flag = 0;
    while(!s.empty()){
        cout << s.top();
        s.pop();
        flag = 1;
    }
    if(flag == 0)
        cout << "0";
    return 0;
}
