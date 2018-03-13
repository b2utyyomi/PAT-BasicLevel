/**********************
author: yomi
date: 18.2.6
ps:整型*整型会超出整型范围，故使用long long int
**********************/
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int powe(int n)
{
    int ans = 1;
    for(int i=0; i<n; i++){
        ans *= 10;
    }
    return ans;
}
long long int toi(string s)
{
    long long int sum = 0;
    int cnt = 0;
    for(int i=s.length()-1; i>=0; i--){
        sum += (s[cnt++]-'0')*powe(i);
    }
    return sum;
}
long long int gcd(long long int a, long long int b)/// 3 15
{

    if(a % b == 0){
        return b;
    }
    return gcd(b, a%b);
}
void print(long long int a1,long long  int b1)
{
    if(a1 == 0){
        cout << "0";
        return;
    }

    if(a1 < b1){
        long long int yue = gcd(a1, b1);
        cout << a1/yue << "/" << b1/yue;
    }
    else if(a1%b1 == 0){
        cout << a1/b1;
    }
    else{
        cout << a1/b1 << ' ';
        long long int k = a1-a1/b1*b1;
        long long int yue = gcd(k, b1);
        cout << k/yue << "/" << b1/yue;
    }
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    long long int a1, b1, a2, b2;
    int i = s1.find("/");
    int j = s2.find("/");
    int t1=0, t2=0;
    int flag = 0;
    string tt = "Inf";
    if(s1[0] == '-')
        t1 = 1;
    if(s2[0] == '-')
        t2 = 1;

    a1 = toi(s1.substr(0+t1, i-t1));
    a2 = toi(s2.substr(0+t2, j-t2));
    b1 = toi(s1.substr(i+1));
    b2 = toi(s2.substr(j+1));
    //cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2;
    //string ans1 = "", ans2 = "", ans3 = "", ans4 = "";
    long long int ans1 = 0, ans2 = 0;
    for(int k=0; k<4; k++){
        if(t1 == 1 && a1!=0)
            cout << "(-";
        print(a1, b1);
        if(t1 == 1 && a1!=0)
            cout << ")";
        if(k == 0){
            cout << " + ";
            ///a1 b1 a2 b2
            long long int aa1 = a1, aa2 = a2;
            ans2 = b2*b1/gcd(b1, b2);

            if(t1 == 1)
                aa1 = -a1;
            if(t2 == 1)
                aa2 = -a2;
            ans1 = aa1*ans2/b1 + aa2*ans2/b2;
            //cout << endl << ans1 << " " << ans2 << endl;

        }
        else if(k == 1){
            cout << " - ";
            long long int aa1 = a1, aa2 = a2;
            ans2 = b2*b1/gcd(b1, b2);

            if(t1 == 1)
                aa1 = -a1;
            if(t2 == 1)
                aa2 = -a2;
            ans1 = aa1*ans2/b1 - aa2*ans2/b2;

        }
        else if(k == 2){
            cout << " * ";
            long long int aa1 = a1, aa2 = a2;
            ans2 = b2*b1;

            if(t1 == 1)
                aa1 = -a1;
            if(t2 == 1)
                aa2 = -a2;
            ans1 = aa1 * aa2;

        }
        else{
            cout << " / ";
            long long int aa1 = a1, aa2 = b2;
            ans2 = a2*b1;
            if(ans2 == 0){
                flag = 1;
            }

            if(t1 == 1)
                aa1 = -a1;
            if(t2 == 1)
                aa2 = -b2;
            ans1 = aa1 * aa2;

        }
        if(t2 == 1 && a2!=0)
            cout << "(-";
        print(a2, b2);
        if(t2 == 1 && a2!=0)
            cout << ")";
        cout << " = ";
        if(flag == 1){
            cout << tt << endl;
            continue;
        }
        long long int ans = ans1;
        if(ans < 0)
            cout << "(-";
        //cout << endl << abs(ans1) << ' ' << abs(ans2) << endl;
        print(abs(ans1), abs(ans2));
        if(ans < 0)
            cout << ")";

        cout << endl;

    }


    return 0;
}
