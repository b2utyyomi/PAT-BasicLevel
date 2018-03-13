/**********************
author: yomi
date: 18.2.2
ps: 注意无有效出生日期的格式控制
**********************/
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <ctime>
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
    int sum = 0;
    int cnt = 0;
    for(int i=s.length()-1; i>=0; i--){
        sum += (s[cnt++]-'0')*powe(i);
    }
    return sum;
}
void split(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));

    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}
int main()
{
    int n;
    std::ios::sync_with_stdio(false);
    int start = clock();

    vector<string>ss;
    //string na[100000], date[100000];
    cin >> n;
    string old, young;
    int cnt = 0;
    int ma_a = 0, mi_a = 10000;
    int ma_b = 0, mi_b = 10000;
    int ma_c = 0, mi_c = 10000;
    for(int i=0; i<n; i++){
        string na, date;
        cin >> na >> date;
        //scanf("%s%s", na, date);
        ss.clear();
        split(date, ss, "/");
        int a = toint(*ss.begin());
        int b = toint(*(ss.begin()+1));
        int c = toint(*(ss.begin()+2));
        //cout << a << ' ' << b << ' ' << c << endl;
        if(a < 1814 || a>2014)
            continue;
        if(a == 1814 && b<9)
            continue;
        if(a == 1814 && b == 9 && c < 6)
            continue;
        if(a==2014 && b>9)
            continue;
        if(a==2014 && b==9 && c>6)
            continue;
        if(a < mi_a ||(a == mi_a && b < mi_b) ||(a == mi_a && b == mi_b && c < mi_c)){
            mi_a = a;
            mi_b = b;
            mi_c = c;
            old = na;
        }
        if(a > ma_a ||(a == ma_a && b>ma_b)||(a==ma_a&&b==ma_b&&c>ma_c)){
            ma_a = a;
            ma_b = b;
            ma_c = c;
            young = na;
        }
        cnt++;

    }
    if(cnt!=0)
        cout << cnt << ' ' << old << ' ' << young;
    else
        cout << "0";
    //DO SOMETHING
    //printf("%.3lf\n",double(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}
/*
2
James 1814/09/05
lala 2014/9/7

*/
