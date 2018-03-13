/**********************
author: yomi
date: 18.2.19
ps: 我又WA了 分析一下 是账号锁定的时机不对
    一旦达到次数，并且又输错了密码之后，
    应该立即锁定的， 而不是下一次输入的时候。
    这题AC率不高，大多数人也是错在这里了吧
    又改了格式 仍然WA
    最后的最后，cin改成了getline 然后AC了 T^T
    其实我想过这个问题 但是题目有说不包含空格
    Tab之类的， 所以故意没写！！！结果大错特错。
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
//            cout << endl;    这样控制格式错误 无法理解
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
