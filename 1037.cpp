/**********************
author: yomi
date: 18.2.5
ps:
**********************/
#include <iostream>
#include <string>
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
int toint(string s)
{
    int cnt = 0;
    int sum = 0;
    for(int i=s.length()-1; i>=0; i--){
        sum += (s[cnt++]-'0')*powe(i);
    }
    return sum;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int pos1[2], pos2[2];
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<s1.length(); i++){
        if(s1[i] == '.'){
            pos1[cnt1++] = i;
        }
    }
    for(int i=0; i<s2.length(); i++){
        if(s2[i] == '.'){
            pos2[cnt2++] = i;
        }
    }
    int g1,g2,si1,si2,k1,k2;
    g1 = toint(s1.substr(0, pos1[0]));
    g2 = toint(s2.substr(0, pos2[0]));
    si1 = toint(s1.substr(pos1[0]+1, pos1[1]-(pos1[0]+1)));
    si2 = toint(s2.substr(pos2[0]+1, pos2[1]-(pos2[0]+1)));;
    k1 = toint(s1.substr(pos1[1]+1,s1.length()-(pos1[1]+1)));
    k2 = toint(s2.substr(pos2[1]+1,s2.length()-(pos2[1]+1)));
    //cout << si1;
    int sum1 = g1*17*29+si1*29+k1;
    int sum2 = g2*17*29+si2*29+k2;
    int sum = sum2-sum1;
    if (sum < 0)
        cout << "-";
    int g = sum/29/17;
    int si = (sum-g*29*17)/29;
    int k = sum-g*29*17-si*29;
    cout << abs(g);
    cout << ".";
    cout << abs(si) << "." << abs(k);
    return 0;
}





