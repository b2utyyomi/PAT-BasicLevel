/**********************
author: yomi
date: 18.2.9
ps:
**********************/
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long int pat = 0, pa = 0, p = 0;///����Ϊlong long int ,����������Ŀ�ϴ󣬳���int��Χ
    for(int i=0; i<s.length(); i++){///�ᵼ�º���������WA
        if(s[i] == 'P'){
            p++;
        }
        else if(s[i] == 'A'){
            pa += p;
        }
        else if(s[i] == 'T'){
            pat += pa;
        }
    }
    cout << pat%1000000007;
    return 0;
}
